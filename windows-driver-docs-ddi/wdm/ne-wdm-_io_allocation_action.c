typedef enum _IO_ALLOCATION_ACTION {
  KeepObject,
  DeallocateObject,
  DeallocateObjectKeepRegisters
} IO_ALLOCATION_ACTION, *PIO_ALLOCATION_ACTION;