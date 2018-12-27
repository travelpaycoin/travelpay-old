from distutils.core import setup
setup(name='btcspendfrom',
      version='1.0',
      description='Command-line utility for bitcoin "coin control"',
      author='Gavin Andresen',
      author_email='gavin@bitcoinfoundattpc-coin.com',
      requires=['jsonrpc'],
      scripts=['spendfrom.py'],
      )
