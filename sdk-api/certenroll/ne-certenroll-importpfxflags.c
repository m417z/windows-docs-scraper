typedef enum ImportPFXFlags {
  ImportNone = 0,
  ImportMachineContext = 0x1,
  ImportForceOverwrite = 0x2,
  ImportSilent = 0x4,
  ImportSaveProperties = 0x8,
  ImportExportable = 0x10,
  ImportExportableEncrypted = 0x20,
  ImportNoUserProtected = 0x40,
  ImportUserProtected = 0x80,
  ImportUserProtectedHigh = 0x100,
  ImportInstallCertificate = 0x200,
  ImportInstallChain = 0x400,
  ImportInstallChainAndRoot = 0x800
} ;