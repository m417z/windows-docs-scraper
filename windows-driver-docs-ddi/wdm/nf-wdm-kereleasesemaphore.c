LONG KeReleaseSemaphore(
  [in, out] PRKSEMAPHORE Semaphore,
  [in]      KPRIORITY    Increment,
  [in]      LONG         Adjustment,
  [in]      BOOLEAN      Wait
);