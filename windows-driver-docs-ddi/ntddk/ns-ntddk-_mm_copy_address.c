typedef struct _MM_COPY_ADDRESS {
  union {
    PVOID            VirtualAddress;
    PHYSICAL_ADDRESS PhysicalAddress;
  };
} MM_COPY_ADDRESS, *PMMCOPY_ADDRESS;