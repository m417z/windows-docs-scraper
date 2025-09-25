typedef struct ENCLAVE_INFORMATION {
  ULONG            EnclaveType;
  ULONG            Reserved;
  PVOID            BaseAddress;
  SIZE_T           Size;
  ENCLAVE_IDENTITY Identity;
} ENCLAVE_INFORMATION;