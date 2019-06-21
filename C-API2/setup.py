from distutils.core import setup, Extension

module1 = Extension('queue_functions', sources = ['func.c'])

setup (name = 'queue_functions,
	version = '1.1',
	description = 'Модуль для работы с очередями',
	ext_modules = [module1])