#define MmGetMdlVirtualAddress(Mdl) \
    ((PVOID) ((PCHAR) ((Mdl)->StartVa) + (Mdl)->ByteOffset))