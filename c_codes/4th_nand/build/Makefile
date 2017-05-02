#root_Makefile
include ../src/Make.defines

all : $(PROGRAM)

$(PROGRAM) : sub_make
	$(LD) -Tlds $(wildcard $(OBJS_DIR)/*.o) -o $@ $(LIBS)
	$(OBJ_COPY) -O binary -S $@ $@.bin
	$(OBJ_DUMP) -D -m arm $@ > dis

sub_make : 
	$(CC) -c ../start_up/start_up.s -o ../start_up/start_up.o
	$(CC) -c ../start_up/system_init.c -o ../start_up/system_init.o -I../include -O0
	@$(MAKE) -C $(ROOT_DIR)/src

.PHONY : clean
	
clean :
	rm -rf $(OBJS_DIR) $(PROGRAM)*
	rm -rf ../start_up/*.o
	rm -rf dis
