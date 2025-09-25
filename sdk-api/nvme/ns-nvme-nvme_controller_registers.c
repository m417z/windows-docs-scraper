typedef struct {
  NVME_CONTROLLER_CAPABILITIES             CAP;
  NVME_VERSION                             VS;
  ULONG                                    INTMS;
  ULONG                                    INTMC;
  NVME_CONTROLLER_CONFIGURATION            CC;
  ULONG                                    Reserved0;
  NVME_CONTROLLER_STATUS                   CSTS;
  NVME_NVM_SUBSYSTEM_RESET                 NSSR;
  NVME_ADMIN_QUEUE_ATTRIBUTES              AQA;
  NVME_ADMIN_SUBMISSION_QUEUE_BASE_ADDRESS ASQ;
  NVME_ADMIN_COMPLETION_QUEUE_BASE_ADDRESS ACQ;
  NVME_CONTROLLER_MEMORY_BUFFER_LOCATION   CMBLOC;
  NVME_CONTROLLER_MEMORY_BUFFER_SIZE       CMBSZ;
  ULONG                                    Reserved2[944];
  ULONG                                    Reserved3[64];
  ULONG                                    Doorbells[0];
} NVME_CONTROLLER_REGISTERS, *PNVME_CONTROLLER_REGISTERS;