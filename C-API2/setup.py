
from distutils.core import setup, Extension

module1 = Extension('queue', sources = ['queue.c'])

setup (name = 'queue',
	version = '1.1',
	description = 'Queuing module ',
	ext_modules = [module1])