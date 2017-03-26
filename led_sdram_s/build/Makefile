#root_Makefile
include ../src/Make.defines

all : $(PROGRAM)

$(PROGRAM) : sub_make
	$(CC_LD) -Ttext 0x30000000 ../start_up/start_up.o $(wildcard $(OBJS_DIR)/*.o) -o $@
	$(CC_CP) -O binary -S $(PROGRAM) $(PROGRAM).bin
	$(CC_DP) -D -m arm $(PROGRAM) > $(PROGRAM).dis

sub_make : 
	$(CC) $(CC_OPT) ../start_up/start_up.o ../start_up/start_up.s $(CFLAGS)
	@$(MAKE) -C $(ROOT_DIR)/src

.PHONY : clean
	
clean :
	rm -rf $(OBJS_DIR) $(PROGRAM)*
	rm -rf ../start_up/start_up.o
