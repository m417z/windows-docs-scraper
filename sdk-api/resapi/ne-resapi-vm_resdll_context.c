typedef enum VM_RESDLL_CONTEXT {
  VmResdllContextTurnOff = 0,
  VmResdllContextSave = 1,
  VmResdllContextShutdown = 2,
  VmResdllContextShutdownForce = 3,
  VmResdllContextLiveMigration = 4
}  *PVM_RESDLL_CONTEXT;