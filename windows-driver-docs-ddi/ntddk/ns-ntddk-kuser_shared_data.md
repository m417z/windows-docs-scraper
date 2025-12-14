## Description

This topic describes the **KUSER_SHARED_DATA** structure.

## Members

### `TickCountLowDeprecated`

Current low 32-bit of tick count.

### `TickCountMultiplier`

Tick count multiplier.

### `InterruptTime`

Current 64-bit interrupt time in 100ns units.

### `SystemTime`

Current 64-bit system time in 100ns units.

### `TimeZoneBias`

Current 64-bit time zone bias.

### `ImageNumberLow`

Low image magic number for the host system.

### `ImageNumberHigh`

High image magic number for the host system.

### `NtSystemRoot[260]`

Copy of system root in unicode. This field must be accessed via the **RtlGetNtSystemRoot** API for an accurate result.

### `MaxStackTraceDepth`

Maximum stack trace depth if tracing enabled.

### `CryptoExponent`

Crypto exponent value.

### `TimeZoneId`

Time zone ID.

### `LargePageMinimum`

Defines the **ULONG** member **LargePageMinimum**.

### `AitSamplingValue`

This value controls the AIT sampling rate.

### `AppCompatFlag`

This value controls switchback processing.

### `RNGSeedVersion`

Current kernel root RNG state seed version.

### `GlobalValidationRunlevel`

This value controls assertion failure handling.

### `TimeZoneBiasStamp`

Defines the **LONG** member **TimeZoneBiasStamp**.

### `NtBuildNumber`

The shared collective build number undecorated with C or F. **GetVersionEx** hides the real number.

### `NtProductType`

Product type. This field must be accessed via the **RtlGetNtProductType** API for an accurate result.

### `ProductTypeIsValid`

Defines the **BOOLEAN** member **ProductTypeIsValid**.

### `Reserved0[1]`

Reserved for future use.

### `NativeProcessorArchitecture`

Defines the **USHORT** member **NativeProcessorArchitecture**.

### `NtMajorVersion`

The NT major version. Each process sees a version from its PEB, but if the process is running with an altered view of the system version, this field is used to correctly identify the version.

### `NtMinorVersion`

The NT minor version. Each process sees a version from its PEB, but if the process is running with an altered view of the system version, this field is used to correctly identify the version.

### `ProcessorFeatures[PROCESSOR_FEATURE_MAX]`

Processor features.

### `Reserved1`

Reserved for future use.

### `Reserved3`

Reserved for future use.

### `TimeSlip`

Time slippage while in debugger.

### `AlternativeArchitecture`

Alternative system architecture. For example, NEC PC98xx on x86.

### `BootId`

Boot sequence, incremented for each boot attempt by the OS loader.

### `SystemExpirationDate`

If the system is an evaluation unit, the following field contains the date and time that the evaluation unit expires. A value of 0 indicates that there is no expiration. A non-zero value is the UTC absolute time that the system expires.

### `SuiteMask`

Suite support. This field must be accessed via the RtlGetSuiteMask API for an accurate result.

### `KdDebuggerEnabled`

TRUE if a kernel debugger is connected/enabled.

### `MitigationPolicies`

Mitigation policies.

### `NXSupportPolicy`

Defines the **UCHAR** member **NXSupportPolicy**.

### `SEHValidationPolicy`

Defines the **UCHAR** member **SEHValidationPolicy**.

### `CurDirDevicesSkippedForDlls`

Defines the **UCHAR** member **CurDirDevicesSkippedForDlls**.

### `Reserved`

Reserved for future use.

### `CyclesPerYield`

Measured duration of a single processor yield, in cycles. This is used by lock packages to determine how many times to spin waiting for a state change before blocking.

### `ActiveConsoleId`

Current console session Id. Always zero on non-TS systems. This field must be accessed via the **RtlGetActiveConsoleId** API for an accurate result.

### `DismountCount`

Force-dismounts cause handles to become invalid. Rather than always probe handles, a serial number of dismounts is maintained that clients can use to see if they need to probe handles.

### `ComPlusPackage`

This field indicates the status of the 64-bit COM+ package on the system. It indicates whether the Intermediate Language (IL) COM+ images need to use the 64-bit COM+ runtime or the 32-bit COM+ runtime.

### `LastSystemRITEventTickCount`

Time in tick count for system-wide last user input across all terminal sessions. For MP performance, it is not updated all the time (for example, once a minute per session). It is used for idle detection.

### `NumberOfPhysicalPages`

Number of physical pages in the system. This can dynamically change as physical memory can be added or removed from a running system.

### `SafeBootMode`

True if the system was booted in safe boot mode.

### `VirtualizationFlags`

Virtualization flags.

### `ArchStartedInEl2`

Keep this bitfield in sync with the one in arc.w.

### `QcSlIsSupported`

Keep this bitfield in sync with the one in arc.w.

### `Reserved12[2]`

Reserved for future use.

### `DUMMYUNIONNAME2`

This is a packed bitfield that contains various flags concerning the system state. They must be manipulated using interlocked operations. **DbgMultiSessionSku** must be accessed via the **RtlIsMultiSessionSku** API for an accurate result.

### `DUMMYUNIONNAME2.SharedDataFlags`

Defines the **ULONG** member **SharedDataFlags**.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2`

Defines the **DUMMYSTRUCTNAME2** structure.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.DbgErrorPortPresent`

For debugger only. Do not use. Use the bit definitions instead.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.DbgElevationEnabled`

For debugger only. Do not use. Use the bit definitions instead.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.DbgVirtEnabled`

For debugger only. Do not use. Use the bit definitions instead.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.DbgInstallerDetectEnabled`

For debugger only. Do not use. Use the bit definitions instead.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.DbgLkgEnabled`

For debugger only. Do not use. Use the bit definitions instead.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.DbgDynProcessorEnabled`

For debugger only. Do not use. Use the bit definitions instead.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.DbgConsoleBrokerEnabled`

For debugger only. Do not use. Use the bit definitions instead.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.DbgSecureBootEnabled`

For debugger only. Do not use. Use the bit definitions instead.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.DbgMultiSessionSku`

For debugger only. Do not use. Use the bit definitions instead.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.DbgMultiUsersInSessionSku`

For debugger only. Do not use. Use the bit definitions instead.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.DbgStateSeparationEnabled`

For debugger only. Do not use. Use the bit definitions instead.

### `DUMMYUNIONNAME2.DUMMYSTRUCTNAME2.SpareBits`

For the debugger only. Do not use. Use the bit definitions instead.

### `DataFlagsPad[1]`

Defines the **ULONG** member **DataFlagsPad**.

### `TestRetInstruction`

Depending on the processor, the code for fast system call will differ. This field is only used on 32-bit systems.

### `QpcFrequency`

Defines the **LONGLONG** member **QpcFrequency**.

### `SystemCall`

On AMD64, this value is initialized to a nonzero value if the system operates with an altered view of the system service call mechanism.

### `Reserved2`

Reserved for future use.

### `FullNumberOfPhysicalPages`

Reserved for future use.

### `SystemCallPad[1]`

Reserved for future use.

### `DUMMYUNIONNAME3`

The 64-bit tick count.

### `DUMMYUNIONNAME3.TickCount`

Defines the **KSYSTEM_TIME** member **TickCount**.

### `DUMMYUNIONNAME3.TickCountQuad`

Defines the **ULONG64** member **TickCountQuad**.

### `DUMMYUNIONNAME3.DUMMYSTRUCTNAME`

Defines **DUMMYSTRUCTNAME**.

### `DUMMYUNIONNAME3.DUMMYSTRUCTNAME.ReservedTickCountOverlay[3]`

Defines the **ULONG** member **ReservedTickCountOverlay**.

### `DUMMYUNIONNAME3.DUMMYSTRUCTNAME.TickCountPad[1]`

Defines the **ULONG** member **TickCountPad**.

### `Cookie`

Cookie for encoding pointers system wide.

### `CookiePad[1]`

Reserved for future use.

### `ConsoleSessionForegroundProcessId`

Client id of the process having the focus in the current active console session id. This field must be accessed via the **RtlGetConsoleSessionForegroundProcessId** API for an accurate result.

### `TimeUpdateLock`

Placeholder for the (internal) time update lock. This data is used to implement the precise time services. It is aligned on a 64-byte cache-line boundary and arranged in the order of typical accesses.

### `BaselineSystemTimeQpc`

The performance counter value used to establish the current system time.

### `BaselineInterruptTimeQpc`

The performance counter value used to compute the last interrupt time.

### `QpcSystemTimeIncrement`

The scaled number of system time seconds represented by a single performance count (this value may vary to achieve time synchronization).

### `QpcInterruptTimeIncrement`

The scaled number of interrupt time seconds represented by a single performance count (this value is constant after the system is booted).

### `QpcSystemTimeIncrementShift`

The scaling shift count applied to the performance counter system time increment.

### `QpcInterruptTimeIncrementShift`

The scaling shift count applied to the performance counter interrupt time increment.

### `UnparkedProcessorCount`

The count of unparked processors.

### `EnclaveFeatureMask[4]`

A bitmask of enclave features supported on this system. This field must be accessed via the **RtlIsEnclaveFeaturePresent** API for an accurate result.

### `TelemetryCoverageRound`

Current coverage round for telemetry based coverage.

### `UserModeGlobalLogger[16]`

The following field is used for ETW user mode global logging (UMGL).

### `ImageFileExecutionOptions`

Settings that can enable the use of Image File Execution Options from HKCU in addition to the original HKLM.

### `LangGenerationCount`

Generation of the kernel structure holding system language information.

### `Reserved4`

Reserved for future use.

### `InterruptTimeBias`

Current 64-bit interrupt time bias in 100ns units.

### `QpcBias`

Current 64-bit performance counter bias, in performance counter units before the shift is applied.

### `ActiveProcessorCount`

Number of active processors.

### `ActiveGroupCount`

Number of active groups.

### `Reserved9`

Reserved for future use.

### `QpcData`

Defines the **USHORT** member QpcData.

### `QpcBypassEnabled`

A boolean indicating whether performance counter queries can read the counter directly (bypassing the system call).

### `QpcReserved`

Reserved for future use.

### `TimeZoneBiasEffectiveStart`

Defines the **LARGE_INTEGER** member **TimeZoneBiasEffectiveStart**.

### `TimeZoneBiasEffectiveEnd`

Defines the **LARGE_INTEGER** member **TimeZoneBiasEffectiveEnd**.

### `XState`

Extended processor state configuration.

### `FeatureConfigurationChangeStamp`

Defines the **KSYSTEM_TIME** member **FeatureConfigurationChangeStamp**.

### `Spare`

Defines the **ULONG** member **Spare**.

### `UserPointerAuthMask`

Defines the **ULONG64** member **UserPointerAuthMask**.

## Remarks

## See also