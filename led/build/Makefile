#root_Makefile
include ../src/Make.defines

all : $(PROGRAM)

$(PROGRAM) : sub_make
	$(CC) $(CC_OPT) $(OBJS_DIR)/start_up.o ../src/start_up.s
	$(CC_LD) -Ttext 0x00000000 $(wildcard $(OBJS_DIR)/*.o) -o $@ $(LIBS)
	$(CC_CP) -O binary -S $(PROGRAM) $(PROGRAM).bin
	$(CC_DP) -D -m arm $(PROGRAM) > $(PROGRAM).dis

sub_make : 
	@$(MAKE) -C $(ROOT_DIR)/src

.PHONY : clean
	
clean :
	rm -rf $(OBJS_DIR) $(PROGRAM)
