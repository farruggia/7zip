
include makefile.common

7za: common
	$(MAKE) -C CPP/7zip/Bundles/Alone all

depend:
	$(MAKE) -C CPP/7zip/Bundles/Alone         depend
	$(MAKE) -C CPP/7zip/Bundles/Alone7z       depend
	$(MAKE) -C CPP/7zip/Bundles/SFXCon        depend
	$(MAKE) -C CPP/7zip/UI/Client7z           depend
	$(MAKE) -C CPP/7zip/UI/Console            depend
	$(MAKE) -C CPP/7zip/Bundles/Format7zFree  depend
	$(MAKE) -C CPP/7zip/Compress/Rar          depend

sfx: common
	$(MKDIR) bin
	$(MAKE) -C CPP/7zip/Bundles/SFXCon  all

common7z:common
	$(MKDIR) bin/Codecs
	$(MAKE) -C CPP/7zip/Bundles/Format7zFree all
	$(MAKE) -C CPP/7zip/Compress/Rar         all

lzham:common
	$(MKDIR) bin/Codecs
	$(MAKE) -C CPP/7zip/Compress/Lzham all

7z: common7z
	$(MAKE) -C CPP/7zip/UI/Console           all

7zG: common7z LangAndHelp
	$(MAKE) -C CPP/7zip/UI/GUI               all

7zFM: common7z LangAndHelp
	$(MAKE) -C CPP/7zip/UI/FileManager       all

clean_C:
	$(MAKE) -C CPP/myWindows                 clean
	$(MAKE) -C CPP/7zip/Bundles/Alone        clean
	$(MAKE) -C CPP/7zip/Bundles/Alone7z      clean
	$(MAKE) -C CPP/7zip/Bundles/SFXCon       clean
	$(MAKE) -C CPP/7zip/UI/Client7z          clean
	$(MAKE) -C CPP/7zip/UI/Console           clean
	$(MAKE) -C CPP/7zip/UI/FileManager       clean
	$(MAKE) -C CPP/7zip/UI/GUI               clean
	$(MAKE) -C CPP/7zip/Bundles/Format7zFree clean
	$(MAKE) -C CPP/7zip/Compress/Rar         clean
	$(MAKE) -C CPP/7zip/Compress/Lzham       clean
	$(MAKE) -C CPP/7zip/Bundles/LzmaCon      clean2
	$(MAKE) -C CPP/7zip/Bundles/AloneGCOV    clean
	$(MAKE) -C CPP/7zip/UI/P7ZIP             clean

LzmaCon:
	$(MAKE) -C CPP/7zip/Bundles/LzmaCon

test_LzmaCon:
	$(MAKE) -C CPP/7zip/Bundles/LzmaCon  test

