# IDENTIFY_DEVICE_DATA structure

## Description

The **IDENTIFY_DEVICE_DATA** structure contains the data retrieved by an ATA identify device data command (0xEC).

> [!NOTE]
> The ATA port driver and ATA miniport driver models may be altered or unavailable in the future. Instead, we recommend using the [Storport driver](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-driver) and [Storport miniport](https://learn.microsoft.com/windows-hardware/drivers/storage/storport-miniport-drivers) driver models.

## Members

### `GeneralConfiguration`

Contains general configuration information.

### `GeneralConfiguration.Reserved1`

Reserved.

### `GeneralConfiguration.Retired3`

This member is no longer used.

### `GeneralConfiguration.ResponseIncomplete`

Indicates that the response was incomplete.

### `GeneralConfiguration.Retired2`

This member is no longer used.

### `GeneralConfiguration.FixedDevice`

Indicates when set to 1 that the device is fixed.

### `GeneralConfiguration.RemovableMedia`

Indicates when set to 1 that the media is removable.

### `GeneralConfiguration.Retired1`

This member is no longer used.

### `GeneralConfiguration.DeviceType`

Indicates when set to 1 that the device is an ATA device.

### `NumCylinders`

Indicates the number of cylinders on the device.

### `SpecificConfiguration`

Specific configuration.

### `NumHeads`

Number of logical heads on the device.

### `Retired1`

This member is no longer used.

### `NumSectorsPerTrack`

Indicates the number of sectors per track.

### `VendorUnique1`

Contains the first ID of the device's vendor.

### `SerialNumber`

Contains the serial number of the device.

### `Retired2`

This member is no longer used.

### `Obsolete1`

This member is obsolete. Do not use.

### `FirmwareRevision`

Contains the revision number of the device's firmware.

### `ModelNumber`

Contains the device's model number.

### `MaximumBlockTransfer`

Contains the maximum number of blocks allowed in a single transfer.

### `VendorUnique2`

Contains the second ID of the device's vendor.

### `TrustedComputing`

Trusted computing.

### `TrustedComputing.FeatureSupported`

Indicates whether the device supports trusted computing.

### `TrustedComputing.Reserved`

Reserved.

### `Capabilities`

Capabilities.

### `Capabilities.CurrentLongPhysicalSectorAlignment`

Current long physical sector alignment.

### `Capabilities.ReservedByte49`

Reserved.

### `Capabilities.DmaSupported`

Indicates that the device supports DMA operations.

### `Capabilities.LbaSupported`

Indicates that the device supports logical block addressing.

### `Capabilities.IordyDisable`

Indicates when set to 1 that I/O channel ready is disabled for the device.

### `Capabilities.IordySupported`

Indicates when set to 1 that I/O channel ready is supported by the device.

### `Capabilities.Reserved1`

Reserved.

### `Capabilities.StandybyTimerSupport`

Indicates when set to 1 that the device supports standby timers.

### `Capabilities.Reserved2`

Reserved.

### `Capabilities.ReservedWord50`

Reserved.

### `ObsoleteWords51`

This member is obsolete. Do not use.

### `TranslationFieldsValid`

Contains a bitfield whose bits indicate which of the bytes in the identify data package contain valid address translation information. For more information about how this bitfield is defined, see the *ATA/ATAPI specification*.

### `Reserved3`

Reserved.

### `FreeFallControlSensitivity`

Free fall control sensitivity.

### `NumberOfCurrentCylinders`

Indicates the number of cylinders on the device.

### `NumberOfCurrentHeads`

Indicates the number of heads on the device.

### `CurrentSectorsPerTrack`

Indicates the number of sectors per track.

### `CurrentSectorCapacity`

Indicates the number of sectors on the device.

### `CurrentMultiSectorSetting`

Indicates the multisector setting.

### `MultiSectorSettingValid`

Indicates when **TRUE** that the multisector setting is valid.

### `ReservedByte59`

Reserved.

### `SanitizeFeatureSupported`

Indicates whether the device supports sanitize.

### `CryptoScrambleExtCommandSupported`

Indicates whether the device supports the crypto scramble command.

### `OverwriteExtCommandSupported`

Indicates whether the device supports the overwrite command.

### `BlockEraseExtCommandSupported`

Indicates whether the device supports block erase.

### `UserAddressableSectors`

Indicates the total number of user-addressable sectors.

### `ObsoleteWord62`

This member is obsolete. Do not use.

### `MultiWordDMASupport`

Indicates which DMA modes the device supports.

### `MultiWordDMAActive`

Indicates which DMA modes are currently selected.

### `AdvancedPIOModes`

Indicates PIO mode support.

### `ReservedByte64`

Reserved.

### `MinimumMWXferCycleTime`

Indicates the minimum multiword DMA transfer cycle time per word.

### `RecommendedMWXferCycleTime`

Indicates the recommended multiword DMA transfer cycle time per word.

### `MinimumPIOCycleTime`

Indicates the minimum PIO transfer cycle time without flow control.

### `MinimumPIOCycleTimeIORDY`

Indicates the minimum PIO transfer cycle time with IORDY flow control.

### `AdditionalSupported`

### `AdditionalSupported.ZonedCapabilities`

### `AdditionalSupported.NonVolatileWriteCache`

### `AdditionalSupported.ExtendedUserAddressableSectorsSupported`

### `AdditionalSupported.DeviceEncryptsAllUserData`

### `AdditionalSupported.ReadZeroAfterTrimSupported`

### `AdditionalSupported.Optional28BitCommandsSupported`

### `AdditionalSupported.IEEE1667`

### `AdditionalSupported.DownloadMicrocodeDmaSupported`

### `AdditionalSupported.SetMaxSetPasswordUnlockDmaSupported`

### `AdditionalSupported.WriteBufferDmaSupported`

### `AdditionalSupported.ReadBufferDmaSupported`

### `AdditionalSupported.DeviceConfigIdentifySetDmaSupported`

### `AdditionalSupported.LPSAERCSupported`

### `AdditionalSupported.DeterministicReadAfterTrimSupported`

### `AdditionalSupported.CFastSpecSupported`

### `ReservedWords70`

### `QueueDepth`

Indicates the maximum queue depth.

### `ReservedWord75`

Reserved.

### `SerialAtaCapabilities`

### `SerialAtaCapabilities.Reserved0`

### `SerialAtaCapabilities.SataGen1`

### `SerialAtaCapabilities.SataGen2`

### `SerialAtaCapabilities.SataGen3`

### `SerialAtaCapabilities.Reserved1`

### `SerialAtaCapabilities.NCQ`

### `SerialAtaCapabilities.HIPM`

### `SerialAtaCapabilities.PhyEvents`

### `SerialAtaCapabilities.NcqUnload`

### `SerialAtaCapabilities.NcqPriority`

### `SerialAtaCapabilities.HostAutoPS`

### `SerialAtaCapabilities.DeviceAutoPS`

### `SerialAtaCapabilities.ReadLogDMA`

### `SerialAtaCapabilities.Reserved2`

### `SerialAtaCapabilities.CurrentSpeed`

### `SerialAtaCapabilities.NcqStreaming`

### `SerialAtaCapabilities.NcqQueueMgmt`

### `SerialAtaCapabilities.NcqReceiveSend`

### `SerialAtaCapabilities.DEVSLPtoReducedPwrState`

### `SerialAtaCapabilities.Reserved3`

### `SerialAtaFeaturesSupported`

### `SerialAtaFeaturesSupported.Reserved0`

### `SerialAtaFeaturesSupported.NonZeroOffsets`

### `SerialAtaFeaturesSupported.DmaSetupAutoActivate`

### `SerialAtaFeaturesSupported.DIPM`

### `SerialAtaFeaturesSupported.InOrderData`

### `SerialAtaFeaturesSupported.HardwareFeatureControl`

### `SerialAtaFeaturesSupported.SoftwareSettingsPreservation`

### `SerialAtaFeaturesSupported.NCQAutosense`

### `SerialAtaFeaturesSupported.DEVSLP`

### `SerialAtaFeaturesSupported.HybridInformation`

### `SerialAtaFeaturesSupported.Reserved1`

### `SerialAtaFeaturesEnabled`

### `SerialAtaFeaturesEnabled.Reserved0`

### `SerialAtaFeaturesEnabled.NonZeroOffsets`

### `SerialAtaFeaturesEnabled.DmaSetupAutoActivate`

### `SerialAtaFeaturesEnabled.DIPM`

### `SerialAtaFeaturesEnabled.InOrderData`

### `SerialAtaFeaturesEnabled.HardwareFeatureControl`

### `SerialAtaFeaturesEnabled.SoftwareSettingsPreservation`

### `SerialAtaFeaturesEnabled.DeviceAutoPS`

### `SerialAtaFeaturesEnabled.DEVSLP`

### `SerialAtaFeaturesEnabled.HybridInformation`

### `SerialAtaFeaturesEnabled.Reserved1`

### `MajorRevision`

Indicates the device's major revision number.

### `MinorRevision`

Indicates the device's minor revision number.

### `CommandSetSupport`

#### Resrved3

Reserved.

### `CommandSetSupport.SmartCommands`

Indicates when **TRUE** that the device supports the SMART feature set.

### `CommandSetSupport.SecurityMode`

Indicates when **TRUE** that the device supports the security mode feature set.

### `CommandSetSupport.RemovableMediaFeature`

### `CommandSetSupport.PowerManagement`

Indicates when **TRUE** that the device supports the mandatory power management feature set.

### `CommandSetSupport.Reserved1`

Reserved.

### `CommandSetSupport.WriteCache`

Indicates when **TRUE** that the device supports a write cache.

### `CommandSetSupport.LookAhead`

Indicates when **TRUE** that the device supports lookahead.

### `CommandSetSupport.ReleaseInterrupt`

Indicates when **TRUE** that the device supports release interrupt.

### `CommandSetSupport.ServiceInterrupt`

Indicates when **TRUE** that the device supports service interrupt.

### `CommandSetSupport.DeviceReset`

Indicates when **TRUE** that the device supports the device reset command.

### `CommandSetSupport.HostProtectedArea`

Indicates when **TRUE** that the device supports the host protected area feature set.

### `CommandSetSupport.Obsolete1`

This member is obsolete. Do not use.

### `CommandSetSupport.WriteBuffer`

Indicates when **TRUE** that the device supports the write buffer command.

### `CommandSetSupport.ReadBuffer`

Indicates when **TRUE** that the device supports the read buffer command.

### `CommandSetSupport.Nop`

Indicates when **TRUE** that the device supports the NOP command.

### `CommandSetSupport.Obsolete2`

Obsolete. Do not use.

### `CommandSetSupport.DownloadMicrocode`

Indicates when **TRUE** that the device supports the DOWNLOAD MICROCODE command.

### `CommandSetSupport.DmaQueued`

Indicates when **TRUE** that the device supports READ/WRITE DMA QUEUED command.

### `CommandSetSupport.Cfa`

Indicates when **TRUE** that the device supports the CFA feature set.

### `CommandSetSupport.AdvancedPm`

Indicates when **TRUE** that the device supports the advanced power management feature set.

### `CommandSetSupport.Msn`

Indicates when **TRUE** that the device supports the media status notification feature set.

### `CommandSetSupport.PowerUpInStandby`

Indicates when **TRUE** that the device supports power-up in standby feature set.

### `CommandSetSupport.ManualPowerUp`

Indicates when **TRUE** that the device supports the SET FEATURES subcommand required to spin up the device after power-up.

### `CommandSetSupport.Reserved2`

Reserved.

### `CommandSetSupport.SetMax`

Indicates when **TRUE** that the device supports the SET MAX security extension command.

### `CommandSetSupport.Acoustics`

Indicates when **TRUE** that the device supports the automatic acoustic management feature set.

### `CommandSetSupport.BigLba`

Indicates when **TRUE** that the device supports the 48-bit address feature set.

### `CommandSetSupport.DeviceConfigOverlay`

### `CommandSetSupport.FlushCache`

### `CommandSetSupport.FlushCacheExt`

### `CommandSetSupport.WordValid83`

### `CommandSetSupport.SmartErrorLog`

### `CommandSetSupport.SmartSelfTest`

### `CommandSetSupport.MediaSerialNumber`

### `CommandSetSupport.MediaCardPassThrough`

### `CommandSetSupport.StreamingFeature`

### `CommandSetSupport.GpLogging`

### `CommandSetSupport.WriteFua`

### `CommandSetSupport.WriteQueuedFua`

### `CommandSetSupport.WWN64Bit`

### `CommandSetSupport.URGReadStream`

### `CommandSetSupport.URGWriteStream`

### `CommandSetSupport.ReservedForTechReport`

### `CommandSetSupport.IdleWithUnloadFeature`

### `CommandSetSupport.WordValid`

### `CommandSetActive`

### `CommandSetActive.SmartCommands`

Indicates when **TRUE** that the device supports the SMART feature set.

### `CommandSetActive.SecurityMode`

Indicates when **TRUE** that the device supports the security mode feature set.

### `CommandSetActive.RemovableMediaFeature`

### `CommandSetActive.PowerManagement`

Indicates when **TRUE** that the device supports the mandatory power management feature set.

### `CommandSetActive.Reserved1`

Reserved.

### `CommandSetActive.WriteCache`

Indicates when **TRUE** that the device supports a write cache.

### `CommandSetActive.LookAhead`

Indicates when **TRUE** that the device supports lookahead.

### `CommandSetActive.ReleaseInterrupt`

Indicates when **TRUE** that the device supports release interrupt.

### `CommandSetActive.ServiceInterrupt`

Indicates when **TRUE** that the device supports service interrupt.

### `CommandSetActive.DeviceReset`

Indicates when **TRUE** that the device supports the device reset command.

### `CommandSetActive.HostProtectedArea`

Indicates when **TRUE** that the device supports the host protected area feature set.

### `CommandSetActive.Obsolete1`

This member is obsolete. Do not use.

### `CommandSetActive.WriteBuffer`

Indicates when **TRUE** that the device supports the write buffer command.

### `CommandSetActive.ReadBuffer`

Indicates when **TRUE** that the device supports the read buffer command.

### `CommandSetActive.Nop`

Indicates when **TRUE** that the device supports the NOP command.

### `CommandSetActive.Obsolete2`

Obsolete. Do not use.

### `CommandSetActive.DownloadMicrocode`

Indicates when **TRUE** that the device supports the DOWNLOAD MICROCODE command.

### `CommandSetActive.DmaQueued`

Indicates when **TRUE** that the device supports READ/WRITE DMA QUEUED command.

### `CommandSetActive.Cfa`

Indicates when **TRUE** that the device supports the CFA feature set.

### `CommandSetActive.AdvancedPm`

Indicates when **TRUE** that the device supports the advanced power management feature set.

### `CommandSetActive.Msn`

Indicates when **TRUE** that the device supports the media status notification feature set.

### `CommandSetActive.PowerUpInStandby`

Indicates when **TRUE** that the device supports power-up in standby feature set.

### `CommandSetActive.ManualPowerUp`

Indicates when **TRUE** that the device supports the SET FEATURES subcommand required to spin up the device after power-up.

### `CommandSetActive.Reserved2`

Reserved.

### `CommandSetActive.SetMax`

Indicates when **TRUE** that the device supports the SET MAX security extension command.

### `CommandSetActive.Acoustics`

Indicates when **TRUE** that the device supports the automatic acoustic management feature set.

### `CommandSetActive.BigLba`

Indicates when **TRUE** that the device supports the 48-bit address feature set.

### `CommandSetActive.DeviceConfigOverlay`

### `CommandSetActive.FlushCache`

### `CommandSetActive.FlushCacheExt`

### `CommandSetActive.Resrved3`

Reserved.

### `CommandSetActive.Words119_120Valid`

### `CommandSetActive.SmartErrorLog`

### `CommandSetActive.SmartSelfTest`

### `CommandSetActive.MediaSerialNumber`

### `CommandSetActive.MediaCardPassThrough`

### `CommandSetActive.StreamingFeature`

### `CommandSetActive.GpLogging`

### `CommandSetActive.WriteFua`

### `CommandSetActive.WriteQueuedFua`

### `CommandSetActive.WWN64Bit`

### `CommandSetActive.URGReadStream`

### `CommandSetActive.URGWriteStream`

### `CommandSetActive.ReservedForTechReport`

### `CommandSetActive.IdleWithUnloadFeature`

### `CommandSetActive.Reserved4`

### `UltraDMASupport`

Contains a bitmap indicating which ultraDMA modes the device supports.

### `UltraDMAActive`

Contains a bitmap indicating which ultraDMA modes are selected.

### `NormalSecurityEraseUnit`

### `NormalSecurityEraseUnit.TimeRequired`

### `NormalSecurityEraseUnit.ExtendedTimeReported`

### `EnhancedSecurityEraseUnit`

### `EnhancedSecurityEraseUnit.TimeRequired`

### `EnhancedSecurityEraseUnit.ExtendedTimeReported`

### `CurrentAPMLevel`

### `ReservedWord91`

### `MasterPasswordID`

### `HardwareResetResult`

Indicates the result of a hardware reset. For more information about the values assigned to this member, see the *ATA/ATAP specification*.

### `CurrentAcousticValue`

Indicates the current acoustic management value.

### `RecommendedAcousticValue`

Contain the device vendor's recommended acoustic management value.

### `StreamMinRequestSize`

### `StreamingTransferTimeDMA`

### `StreamingAccessLatencyDMAPIO`

### `StreamingPerfGranularity`

### `Max48BitLBA`

Contains the maximum user LBA for the 48-bit address feature set.

### `StreamingTransferTime`

### `DsmCap`

### `PhysicalLogicalSectorSize`

### `PhysicalLogicalSectorSize.LogicalSectorsPerPhysicalSector`

### `PhysicalLogicalSectorSize.Reserved0`

### `PhysicalLogicalSectorSize.LogicalSectorLongerThan256Words`

### `PhysicalLogicalSectorSize.MultipleLogicalSectorsPerPhysicalSector`

### `PhysicalLogicalSectorSize.Reserved1`

Reserved.

### `InterSeekDelay`

### `WorldWideName`

### `ReservedForWorldWideName128`

### `ReservedForTlcTechnicalReport`

### `WordsPerLogicalSector`

### `CommandSetSupportExt`

#### Reserved1

Reserved.

### `CommandSetSupportExt.ReservedForDrqTechnicalReport`

### `CommandSetSupportExt.WriteReadVerify`

### `CommandSetSupportExt.WriteUncorrectableExt`

### `CommandSetSupportExt.ReadWriteLogDmaExt`

### `CommandSetSupportExt.DownloadMicrocodeMode3`

### `CommandSetSupportExt.FreefallControl`

### `CommandSetSupportExt.SenseDataReporting`

### `CommandSetSupportExt.ExtendedPowerConditions`

### `CommandSetSupportExt.Reserved0`

### `CommandSetSupportExt.WordValid`

### `CommandSetActiveExt`

### `CommandSetActiveExt.ReservedForDrqTechnicalReport`

### `CommandSetActiveExt.WriteReadVerify`

### `CommandSetActiveExt.WriteUncorrectableExt`

### `CommandSetActiveExt.ReadWriteLogDmaExt`

### `CommandSetActiveExt.DownloadMicrocodeMode3`

### `CommandSetActiveExt.FreefallControl`

### `CommandSetActiveExt.SenseDataReporting`

### `CommandSetActiveExt.ExtendedPowerConditions`

### `CommandSetActiveExt.Reserved0`

### `CommandSetActiveExt.Reserved1`

Reserved.

### `ReservedForExpandedSupportandActive`

### `MsnSupport`

Indicates when **TRUE** that the device supports media status notification.

### `ReservedWord127`

### `SecurityStatus`

Contains a bitmap that indicates the security status. For more information about the meaning of each individual bit, see the *ATA/ATAPI specification*.

### `SecurityStatus.SecuritySupported`

### `SecurityStatus.SecurityEnabled`

### `SecurityStatus.SecurityLocked`

### `SecurityStatus.SecurityFrozen`

### `SecurityStatus.SecurityCountExpired`

### `SecurityStatus.EnhancedSecurityEraseSupported`

### `SecurityStatus.Reserved0`

### `SecurityStatus.SecurityLevel`

### `SecurityStatus.Reserved1`

Reserved.

### `ReservedWord129`

Reserved.

### `CfaPowerMode1`

### `CfaPowerMode1.MaximumCurrentInMA`

### `CfaPowerMode1.CfaPowerMode1Disabled`

### `CfaPowerMode1.CfaPowerMode1Required`

### `CfaPowerMode1.Reserved0`

### `CfaPowerMode1.Word160Supported`

### `ReservedForCfaWord161`

Words 161-168

### `NominalFormFactor`

### `ReservedWord168`

### `DataSetManagementFeature`

### `DataSetManagementFeature.SupportsTrim`

### `DataSetManagementFeature.Reserved0`

### `AdditionalProductID`

### `ReservedForCfaWord174`

### `CurrentMediaSerialNumber`

Words 176-205

### `SCTCommandTransport`

### `SCTCommandTransport.Supported`

### `SCTCommandTransport.Reserved0`

### `SCTCommandTransport.WriteSameSuported`

### `SCTCommandTransport.ErrorRecoveryControlSupported`

### `SCTCommandTransport.FeatureControlSuported`

### `SCTCommandTransport.DataTablesSuported`

### `SCTCommandTransport.Reserved1`

### `SCTCommandTransport.VendorSpecific`

### `ReservedWord207`

Words 207-208

### `BlockAlignment`

### `BlockAlignment.AlignmentOfLogicalWithinPhysical`

### `BlockAlignment.Word209Supported`

### `BlockAlignment.Reserved0`

### `WriteReadVerifySectorCountMode3Only`

Words 210-211

### `WriteReadVerifySectorCountMode2Only`

Words 212-213

### `NVCacheCapabilities`

### `NVCacheCapabilities.NVCachePowerModeEnabled`

### `NVCacheCapabilities.Reserved0`

### `NVCacheCapabilities.NVCacheFeatureSetEnabled`

### `NVCacheCapabilities.Reserved1`

Reserved.

### `NVCacheCapabilities.NVCachePowerModeVersion`

### `NVCacheCapabilities.NVCacheFeatureSetVersion`

### `NVCacheSizeLSW`

### `NVCacheSizeMSW`

### `NominalMediaRotationRate`

### `ReservedWord218`

### `NVCacheOptions`

### `NVCacheOptions.NVCacheEstimatedTimeToSpinUpInSeconds`

### `NVCacheOptions.Reserved`

### `WriteReadVerifySectorCountMode`

### `ReservedWord220`

Words 220-254

### `ReservedWord221`

### `TransportMajorVersion`

### `TransportMajorVersion.MajorVersion`

### `TransportMajorVersion.TransportType`

### `TransportMinorVersion`

### `ReservedWord224`

### `ExtendedNumberOfUserAddressableSectors`

### `MinBlocksPerDownloadMicrocodeMode03`

### `MaxBlocksPerDownloadMicrocodeMode03`

### `ReservedWord236`

### `Signature`

Indicates the disk signature.

### `CheckSum`

Indicates the checksum.