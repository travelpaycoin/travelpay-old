// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Copyright (c) 2018 The Tpc Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
        (       0,	uint256("0000235abe5c5e69c7850d5627463f9574ccc1b83acb1d13ba1c3919e7374b71") ); 
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1034845571, // * UNIX timestamp of last checkpoint block
    2002764,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    2000        // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
	(       1,      uint256("000000b86fdd7f2ae9e9973e73790492989113075a2d5c581495ab7bb2ad5711") ) // First block 
	(  370000,      uint256("c2761da33448b864d880503bfd9a94961c93ecc539360e466336d13b2569142f") );// Fork March 2018

static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1513532336,
    742197,
    2000};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x671d0510c128608897d98d1819d26b40810c8b7e4901447a909c87a9edc2f5ec"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1518696183,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params() const
{
    assert(this);
    static CBigNum bnTrustedModulus(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParams = libzerocoin::ZerocoinParams(bnTrustedModulus);

    return &ZCParams;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x70;              
        pchMessageStart[1] = 0x72;              
        pchMessageStart[2] = 0x74;             
        pchMessageStart[3] = 0x76;
        vAlertPubKey = ParseHex("09cc24ab003c828cdd9cf4eb2ebbde8esdfsdfsdsdfsdfsfsdfsdf1cecb3bbfa8b3127fcb9dd9b84d44112080827ed7c49a648af9fe788ff42e316aee665879c553f099e55299d6b54edd7e0");
        nDefaultPort = 10666;                   
        bnProofOfWorkLimit  = (~uint256(0) >> 16);
        bnProofOfStakeLimit = (~uint256(0) >> 20); 
        nSubsidyHalvingInterval = 210000;       // Halving interval
        nMaxReorganizationDepth = 100;          
        nEnforceBlockUpgradeMajority = 750;     
        nRejectBlockOutdatedMajority = 950;     
        nToCheckBlockUpgradeMajority = 1000;    
        nMinerThreads = 0;                          // Obsolete (**TODO**)
        nTargetTimespanMidas = 7 * 24 * 60 * 60;    // 1 week
        nTargetTimespanDGW = 1 * 60;                // 1 day
        nTargetSpacing = 1 * 64;                    // 1 minute
        nMaturity = 60;                             // Block maturity   
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 21000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 250;                         // PoW Phase 3 End
        nMidasStartHeight = 95550000;                   // MIDAS startheight, first big attack
        nMidasStartTime = 1837631395;                 // Time when MIDAS started and old algorithm stopped
        nDGWStartHeight = 95550000;                     // Startheight of DGW
        nDGWStartTime = 1837631395;              // GMT: Saturday, March 24, 2018 12:27:45 AM - Exact time when DGW algorithm starts and old MIDAS stops
        nZerocoinStartHeight = 95550000;                // Zerocoin start height, starts together with DGW
        nZerocoinStartTime = 1837631395;             // GMT: Saturday, March 24, 2018 12:27:45 AM, 
        nBlockEnforceSerialRange = 5550137;            // Enforce serial range starting this block
        nBlockRecalculateAccumulators = 5550137;       // Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 99999999;             // 1110; //First block that bad serials emerged (currently we do not have any) *** TODO ***
        nBlockLastGoodCheckpoint = 95550137;            // Last valid accumulator checkpoint (currently we do not have any) *** TODO ***
        nBlockEnforceInvalidUTXO = 95550137;            // Start enforcing the invalid UTXO's's

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "A better Travel Pay experience is from our TPC";
        genesis.nTime = 1545722825;                                        // GMT: Thursday, February 2, 2017 2:30:00 PM

        CMutableTransaction txNew;
        txNew.nTime = genesis.nTime;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 0 << CScriptNum(42) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 1 * COIN;
	txNew.vout[0].SetEmpty();
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nBits = 0x1f00ffff;
        genesis.nNonce = 218754;

        hashGenesisBlock = genesis.GetHash();
/*
for(int ii=100000;ii<1000000;ii++) {
	genesis.nNonce = ii;
	printf("i=%7d, hash = %s  , root = %s\n",ii,genesis.GetHash().GetHex().c_str(),genesis.hashMerkleRoot.GetHex().c_str());
}
*/
        assert(hashGenesisBlock == uint256("0x00000f8b302818ef06fb592a2ddee46f7dac61760d9318702972f521d4f4f983"));
        assert(genesis.hashMerkleRoot == uint256("0x0dec2ffe7593eb7bbc3434772143556c1de0f74e0b843cb399104ee6dc279951"));

        // Tpc addresses start with 'i'
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 66);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 105);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 105);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x88)(0xB2)(0x1E).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x88)(0xAD)(0xE4).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x77).convert_to_container<std::vector<unsigned char> >(); // (**TODO**)

        //convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));
	vSeeds.push_back(CDNSSeedData("n1", "n1.travelpaycoin.org"));
	vSeeds.push_back(CDNSSeedData("n2", "n2.travelpaycoin.org"));
	vSeeds.push_back(CDNSSeedData("n3", "n3.travelpaycoin.org"));


        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "04f8c457bd279e667228d38faf2032958ee80ead5ec3d04ab92eeab54ac078ea2a79a2a03dee10634123cc47ea795699bd02b6370e040b622b2f15bcc56dafc2b7";
        strObfuscationPoolDummyAddress = "TravelpaycoinDarksendPoo1DummyAdy4viSr";
        nStartMasternodePayments = 1558696182; // GMT: Thursday, 15. February 2018 12:03:02

        /** Zerocoin */
        zerocoinModulus = "25195908475617893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892955591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733035974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798443387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344351901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023627381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 8; //Block headers must be this version once zerocoin is active
        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0xdb;
        pchMessageStart[1] = 0x86;
        pchMessageStart[2] = 0xfc;
        pchMessageStart[3] = 0x69;
        vAlertPubKey = ParseHex("0432f3e3c6c8ce236579b3223debc2b684f0ffa14fd3fe6813eafe3f3dd3b45664d1efbdfe43441edc83d1c4507ab9bd395c8134797e04457965031a4b6413bb1a");
        nDefaultPort = 27170;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespanMidas = 7 * 24 * 60 * 60;   // 1 week
        nTargetTimespanDGW = 1 * 60;               // 1 day
        nTargetSpacing = 1 * 60;                   // 64 seconds
        nMaturity = 15;
        nMasternodeCountDrift = 4;

        nLastPOWBlock = 300;
        nMidasStartHeight = 75000;
        nMidasStartTime = 1497209344;
        nZerocoinStartHeight = 331100;              // Zerocoin start height
        nZerocoinStartTime = 1521414629;            // GMT: Sunday, March 18, 2018 11:10:29 PM
        nDGWStartHeight = nZerocoinStartHeight;
        nDGWStartTime = nZerocoinStartTime;
        nBlockEnforceSerialRange = 10000000;        // Enforce serial range starting this block
        nBlockRecalculateAccumulators = 10000000;   // Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 99999999;           // 1110; //First block that bad serials emerged (currently we do not have any) *** TODO ***
        nBlockLastGoodCheckpoint = 10000000;        // Last valid accumulator checkpoint (currently we do not have any) *** TODO ***
        nBlockEnforceInvalidUTXO = 10000000;        // Start enforcing the invalid UTXO's
        

        const char* pszTimestamp = "The Guardian: [2nd Feb 2017] Finsbury Park mosque wins apology and damages from Thomson Reuters";
        // CTestNetParams inherits from CMainParams; update what's needed.
        genesis.nTime = 1491737471;                                         // GMT: Thursday, February 2, 2017 2:30:00 PM

        genesis.vtx.clear();

        CMutableTransaction txNew;
        txNew.nTime = genesis.nTime;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 1491737471 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 1 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("045622582bdfad9366cdff9652d35a562af17ea4e3462d32cd988b32919ba2ff4bc806485be5228185ad3f75445039b6e744819c4a63304277ca8d20c99a6acec8") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);

        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nBits = 0x1e00ffff;
        genesis.nNonce = 1603027;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x0000002bed128b6b2a62bd8edd4e6f8a414eac38e256aa0194adb8c93fe18132"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("1", "testnet.seeder.baseserv.com")); // Tpc's official testseed 1
        vSeeds.push_back(CDNSSeedData("2", "testnet.seeder.uksafedns.net")); // Tpc's official testseed 2
        // Testnet Tpc addresses start with 'g'
        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 97);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 196);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239); 
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x04)(0x35)(0x87)(0xcf).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x04)(0x35)(0x83)(0x91).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "0470e14fc60a25e0eb4f6b1fe280e4c3f9427f7bb8b38f14a0c310c2e56402bdce0f25049bf22351dc3d07f389d4d433b339d8e1b991784f11df68f50340185c1d";
        strObfuscationPoolDummyAddress = "TMPUBzcsHZawA32XYYDF9FHQp6icv492CV";
        nStartMasternodePayments = 1558696182; // GMT: Thursday, 15. February 2018 12:03:03

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 8; //Block headers must be this version once zerocoin is active
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        /* 1276a1fa */
        pchMessageStart[0] = 0xb5;
        pchMessageStart[1] = 0x9a;
        pchMessageStart[2] = 0x39;
        pchMessageStart[3] = 0x9e;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespanMidas = 7 * 24 * 60 * 60;// 1 week
        nTargetTimespanDGW = 24 * 60 * 60;      // 1 day
        nTargetSpacing = 1 * 60;                // 1 minute
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1519927200;             // GMT: Thursday, March 1, 2018 6:00:00 PM
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 0x496f6e;                // hex 57 47 52 in text = TPC

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 17270;
        assert(hashGenesisBlock == uint256("0xe6f63a91cd05b42f94ba60e359d5c9d62faf9c9733d9b523a343281e1c267d46"));

        vFixedSeeds.clear();                    //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();                         //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 27770;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
