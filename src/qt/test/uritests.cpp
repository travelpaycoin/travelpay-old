// Copyright (c) 2009-2014 The Bitcoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "uritests.h"

#include "guiutil.h"
#include "walletmodel.h"

#include <QUrl>

void URITests::uriTests()
{
    SendCoinsRecipient rv;
    QUrl uri;
    uri.setUrl(QString("tpc:ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH?req-dontexist="));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("tpc:ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH?dontexist="));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("tpc:ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH?label=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH"));
    QVERIFY(rv.label == QString("Some Example Address"));
    QVERIFY(rv.amount == 0);

    uri.setUrl(QString("tpc:ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH?amount=0.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100000);

    uri.setUrl(QString("tpc:ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH?amount=1.001"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH"));
    QVERIFY(rv.label == QString());
    QVERIFY(rv.amount == 100100000);

    uri.setUrl(QString("tpc:ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH?amount=100&label=Some Example"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH"));
    QVERIFY(rv.amount == 10000000000LL);
    QVERIFY(rv.label == QString("Some Example"));

    uri.setUrl(QString("tpc:ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH?message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));
    QVERIFY(rv.address == QString("ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH"));
    QVERIFY(rv.label == QString());

    QVERIFY(GUIUtil::parseBitcoinURI("tpc://ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH?message=Some Example Address", &rv));
    QVERIFY(rv.address == QString("ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH"));
    QVERIFY(rv.label == QString());

    uri.setUrl(QString("tpc:ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH?req-message=Some Example Address"));
    QVERIFY(GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("tpc:ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH?amount=1,000&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));

    uri.setUrl(QString("tpc:ihxnvv8mMLcQd52bpy7hASw9BnL35FmRuH?amount=1,000.0&label=Some Example"));
    QVERIFY(!GUIUtil::parseBitcoinURI(uri, &rv));
}
