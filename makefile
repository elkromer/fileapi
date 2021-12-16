PROCMON="C:\Program Files\ProcessMonitor\Procmon64.exe"

all: compile

compile:
	gcc main.c -o run.exe

clean:
	del run.exe

start: compile
	.\run.exe

proc:
	$(PROCMON)