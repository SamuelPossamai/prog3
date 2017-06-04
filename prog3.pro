######################################################################
# Automatically generated by qmake (3.0) sab mai 27 18:29:43 2017
######################################################################


TEMPLATE = app
TARGET = main
INCLUDEPATH += . carteado/p3 carteado/src/p3
FRAMEWORK_PATH = carteado/src/p3

DEBUGGER = gdb
DEBUGFLAGS = -g

MEMCHECKER = valgrind
MEMCHECKFLAGS = 

STDPROJECT = BlackJack
isEmpty(PROJECT){ PROJECT = $$STDPROJECT }

# Input
HEADERS += $$system("find $${FRAMEWORK_PATH} -type f -name '*.h'") $$system("find $${PROJECT} -type f -name '*.h'")
SOURCES += $$system("find $${FRAMEWORK_PATH} -type f -name '*.cpp' ! -name 'moc_*'") $$system("find $${PROJECT} -type f -name '*.cpp' ! -name 'moc_*'")

QT += widgets gui

CONFIG += c++14


veryclean.depends = clean
veryclean.commands = find . -type f -executable -exec rm {} + ; find . -type f -name '*.o' -exec rm {} + ; find . -type f -name 'moc_*' -exec rm {} +

run.depends = $$TARGET
run.commands = ./$$TARGET

extraclean.depends = veryclean distclean

DEBUG.target = debug
DEBUG.depends = debug_flags $$TARGET
DEBUG.commands = $$DEBUGGER ./$$TARGET

isEmpty(DEBUGFLAGS) {} else {debug_flags.commands = "$(eval CXXFLAGS += $${DEBUGFLAGS} -O0)"}

memcheck.depends = memcheck_flags $$TARGET
memcheck.commands = $$MEMCHECKER ./$$TARGET

isEmpty(MEMCHECKFLAGS) {} else {memcheck_flags.commands = "$(eval CXXFLAGS += $${MEMCHECKFLAGS})"}

QMAKE_EXTRA_TARGETS = veryclean run extraclean DEBUG debug_flags memcheck memcheck_flags


