.PHONY: clean All

All:
	@echo "----------Building project:[ FS_DSSE - Debug ]----------"
	@cd "FS_DSSE" && "$(MAKE)" -f  "FS_DSSE.mk"
clean:
	@echo "----------Cleaning project:[ FS_DSSE - Debug ]----------"
	@cd "FS_DSSE" && "$(MAKE)" -f  "FS_DSSE.mk" clean
