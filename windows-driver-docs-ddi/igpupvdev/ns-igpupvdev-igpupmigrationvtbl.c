typedef struct IGPUPMigrationVtbl {
  void     *b;
  HRESULT(IGPUPMigration *This,REFIID riid, void **ppvObject) * )(QueryInterface;
  ULONG()(IGPUPMigration *This)   * AddRef;
  ULONG()(IGPUPMigration *This)   * Release;
  HRESULT((IGPUPMigration *This,PLUID DeviceLuid,UINT64 *Length,BYTE SaveBuffer * )SaveImmutableGpup[];
  HRESULT()(IGPUPMigration *This,PLUID DeviceLuid,UINT64 Length,BYTE RestoreBuffer * RestoreImmutableGpup[];
} IGPUPMigrationVtbl;