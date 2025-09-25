typedef struct {
  CHAR PCIVendorID[4];
  CHAR ModelNumber[40];
  CHAR NamespaceID[4];
  CHAR SerialNumber[20];
} NVME_SCSI_NAME_STRING, *PNVME_SCSI_NAME_STRING;