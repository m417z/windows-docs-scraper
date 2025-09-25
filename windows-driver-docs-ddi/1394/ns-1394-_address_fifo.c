typedef struct _ADDRESS_FIFO {
  SLIST_ENTRY FifoList;
  PMDL        FifoMdl;
} ADDRESS_FIFO, *PADDRESS_FIFO;