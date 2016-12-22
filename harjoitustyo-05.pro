TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
CONFIG += c++11

SOURCES += main.cpp \
    luetiedosto.cpp \
    materiaalit.cpp \
    lista.cpp \
    mlista.cpp

HEADERS += \
    luetiedosto.hh \
    materiaalit.hh \
    lista.hh \
    mlista.hh

OTHER_FILES += \
    a.txt \
    b.txt \
    c.txt

