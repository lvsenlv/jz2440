#root_Makefile
include ../src/Make.defines

all : $(PROGRAM)

$(PROGRAM) : sub_make
	$(CC) $(CC_OPT) ../start_up/start_up.o ../start_up/start_up.s -Wall
	$(CC) $(CC_OPT) ../start_up/start_up_conf.o ../start_up/start_up_conf.c -Wall
	#$(CC_LD) -Tlds -L./object -o $@
	$(CC_LD) -Tlds $(wildcard $(OBJS_DIR)/*.o) -o $@
	$(CC_CP) -O binary -S $(PROGRAM) $(PROGRAM).bin
	$(CC_DP) -D -m arm $(PROGRAM) > dis

sub_make : 
	@$(MAKE) -C $(ROOT_DIR)/src

.PHONY : clean
	
clean :
	rm -rf $(OBJS_DIR) $(PROGRAM)* dis
	rm -rf ../start_up/*.o
