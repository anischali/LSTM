CC = g++
RM = rm -f
# déclaration des options du compilateur
CFLAGS = 
CPPFLAGS = -g -I.
LDFLAGS = -lm 
# définition des fichiers et dossiers
PROGNAME = LSTM
VERSION = 1.0
distdir = $(PROGNAME)-$(VERSION)
HEADERS = 
SOURCES =  util.cpp  main.cpp
OBJ = $(SOURCES:.cpp=.o)
all: $(PROGNAME)
$(PROGNAME): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(PROGNAME) 
%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@ 
clean:
	@$(RM) -r $(PROGNAME) $(OBJ) *~