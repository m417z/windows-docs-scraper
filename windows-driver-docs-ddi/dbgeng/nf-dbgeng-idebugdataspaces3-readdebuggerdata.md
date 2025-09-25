# IDebugDataSpaces3::ReadDebuggerData

## Description

The **ReadDebuggerData** method returns information about the target that the [debugger engine](https://learn.microsoft.com/windows-hardware/drivers/debugger/introduction) has queried or determined during the current session. The available information includes the locations of certain key target kernel locations, specific status values, and a number of other things.

## Parameters

### `Index` [in]

Specifies the index of the data to retrieve. The following values are valid:

| Value | Return Type | Description |
| --- | --- | --- |
| DEBUG_DATA_KernBase | ULONG64 | Returns the base address of the kernel image. |
| DEBUG_DATA_BreakpointWithStatusAddr | ULONG64 | Returns the address of the kernel function **BreakpointWithStatusInstruction**. |
| DEBUG_DATA_SavedContextAddr | ULONG64 | Returns the address of saved context record during a bugcheck. It is only valid after a bugcheck. |
| DEBUG_DATA_KiCallUserModeAddr | ULONG64 | Returns the address of the kernel function **KiCallUserMode**. |
| DEBUG_DATA_KeUserCallbackDispatcherAddr | ULONG64 | Returns the kernel variable **KeUserCallbackDispatcher**. |
| DEBUG_DATA_PsLoadedModuleListAddr | ULONG64 | Returns the address of the kernel variable **PsLoadedModuleList**. |
| DEBUG_DATA_PsActiveProcessHeadAddr | ULONG64 | Returns the address of the kernel variable **PsActiveProcessHead**. |
| DEBUG_DATA_PspCidTableAddr | ULONG64 | Returns the address of the kernel variable **PspCidTable**. |
| DEBUG_DATA_ExpSystemResourcesListAddr | ULONG64 | Returns the address of the kernel variable **ExpSystemResourcesList**. |
| DEBUG_DATA_ExpPagedPoolDescriptorAddr | ULONG64 | Returns the address of the kernel variable **ExpPagedPoolDescriptor**. |
| DEBUG_DATA_ExpNumberOfPagedPoolsAddr | ULONG64 | Returns the address of the kernel variable **ExpNumberOfPagedPools**. |
| DEBUG_DATA_KeTimeIncrementAddr | ULONG64 | Returns the address of the kernel variable **KeTimeIncrement**. |
| DEBUG_DATA_KeBugCheckCallbackListHeadAddr | ULONG64 | Returns the address of the kernel variable **KeBugCheckCallbackListHead**. |
| DEBUG_DATA_KiBugcheckDataAddr | ULONG64 | Returns the kernel variable **KiBugCheckData**. |
| DEBUG_DATA_IopErrorLogListHeadAddr | ULONG64 | Returns the address of the kernel variable **IopErrorLogListHead**. |
| DEBUG_DATA_ObpRootDirectoryObjectAddr | ULONG64 | Returns the address of the kernel variable **ObpRootDirectoryObject**. |
| DEBUG_DATA_ObpTypeObjectTypeAddr | ULONG64 | Returns the address of the kernel variable **ObpTypeObjectType**. |
| DEBUG_DATA_MmSystemCacheStartAddr | ULONG64 | Returns the address of the kernel variable **MmSystemCacheStart**. |
| DEBUG_DATA_MmSystemCacheEndAddr | ULONG64 | Returns the address of the kernel variable **MmSystemCacheEnd**. |
| DEBUG_DATA_MmSystemCacheWsAddr | ULONG64 | Returns the address of the kernel variable **MmSystemCacheWs**. |
| DEBUG_DATA_MmPfnDatabaseAddr | ULONG64 | Returns the address of the kernel variable **MmPfnDatabase**. |
| DEBUG_DATA_MmSystemPtesStartAddr | ULONG64 | Returns the kernel variable **MmSystemPtesStart**. |
| DEBUG_DATA_MmSystemPtesEndAddr | ULONG64 | Returns the kernel variable **MmSystemPtesEnd**. |
| DEBUG_DATA_MmSubsectionBaseAddr | ULONG64 | Returns the address of the kernel variable **MmSubsectionBase**. |
| DEBUG_DATA_MmNumberOfPagingFilesAddr | ULONG64 | Returns the address of the kernel variable **MmNumberOfPagingFiles**. |
| DEBUG_DATA_MmLowestPhysicalPageAddr | ULONG64 | Returns the address of the kernel variable **MmLowestPhysicalPage**. |
| DEBUG_DATA_MmHighestPhysicalPageAddr | ULONG64 | Returns the address of the kernel variable **MmHighestPhysicalPage**. |
| DEBUG_DATA_MmNumberOfPhysicalPagesAddr | ULONG64 | Returns the address of the kernel variable **MmNumberOfPhysicalPages**. |
| DEBUG_DATA_MmMaximumNonPagedPoolInBytesAddr | ULONG64 | Returns the address of the kernel variable **MmMaximumNonPagedPoolInBytes**. |
| DEBUG_DATA_MmNonPagedSystemStartAddr | ULONG64 | Returns the address of the kernel variable **MmNonPagedSystemStart**. |
| DEBUG_DATA_MmNonPagedPoolStartAddr | ULONG64 | Returns the address of the kernel variable **MmNonPagedPoolStart**. |
| DEBUG_DATA_MmNonPagedPoolEndAddr | ULONG64 | Returns the address of the kernel variable **MmNonPagedPoolEnd**. |
| DEBUG_DATA_MmPagedPoolStartAddr | ULONG64 | Returns the address of the kernel variable **MmPagedPoolStart**. |
| DEBUG_DATA_MmPagedPoolEndAddr | ULONG64 | Returns the address of the kernel variable **MmPagedPoolEnd**. |
| DEBUG_DATA_MmPagedPoolInformationAddr | ULONG64 | Returns the address of the kernel variable **MmPagedPoolInfo**. |
| DEBUG_DATA_MmPageSize | ULONG64 | Returns the page size. |
| DEBUG_DATA_MmSizeOfPagedPoolInBytesAddr | ULONG64 | Returns the address of the kernel variable **MmSizeOfPagedPoolInBytes**. |
| DEBUG_DATA_MmTotalCommitLimitAddr | ULONG64 | Returns the address of the kernel variable **MmTotalCommitLimit**. |
| DEBUG_DATA_MmTotalCommittedPagesAddr | ULONG64 | Returns the address of the kernel variable **MmTotalCommittedPages**. |
| DEBUG_DATA_MmSharedCommitAddr | ULONG64 | Returns the address of the kernel variable **MmSharedCommit**. |
| DEBUG_DATA_MmDriverCommitAddr | ULONG64 | Returns the address of the kernel variable **MmDriverCommit**. |
| DEBUG_DATA_MmProcessCommitAddr | ULONG64 | Returns the address of the kernel variable **MmProcessCommit**. |
| DEBUG_DATA_MmPagedPoolCommitAddr | ULONG64 | Returns the address of the kernel variable **MmPagedPoolCommit**. |
| DEBUG_DATA_MmExtendedCommitAddr | ULONG64 | Returns the address of the kernel variable **MmExtendedCommit**.. |
| DEBUG_DATA_MmZeroedPageListHeadAddr | ULONG64 | Returns the address of the kernel variable **MmZeroedPageListHead**. |
| DEBUG_DATA_MmFreePageListHeadAddr | ULONG64 | Returns the address of the kernel variable **MmFreePageListHead**. |
| DEBUG_DATA_MmStandbyPageListHeadAddr | ULONG64 | Returns the address of the kernel variable **MmStandbyPageListHead**. |
| DEBUG_DATA_MmModifiedPageListHeadAddr | ULONG64 | Returns the address of the kernel variable **MmModifiedPageListHead**. |
| DEBUG_DATA_MmModifiedNoWritePageListHeadAddr | ULONG64 | Returns the address of the kernel variable **MmModifiedNoWritePageListHead**. |
| DEBUG_DATA_MmAvailablePagesAddr | ULONG64 | Returns the address of the kernel variable **MmAvailablePages**. |
| DEBUG_DATA_MmResidentAvailablePagesAddr | ULONG64 | Returns the address of the kernel variable **MmResidentAvailablePages**. |
| DEBUG_DATA_PoolTrackTableAddr | ULONG64 | Returns the address of the kernel variable **PoolTrackTable**. |
| DEBUG_DATA_NonPagedPoolDescriptorAddr | ULONG64 | Returns the address of the kernel variable **NonPagedPoolDescriptor**. |
| DEBUG_DATA_MmHighestUserAddressAddr | ULONG64 | Returns the address of the kernel variable **MmHighestUserAddress**. |
| DEBUG_DATA_MmSystemRangeStartAddr | ULONG64 | Returns the address of the kernel variable **MmSystemRangeStart**. |
| DEBUG_DATA_MmUserProbeAddressAddr | ULONG64 | Returns the address of the kernel variable **MmUserProbeAddress**. |
| DEBUG_DATA_KdPrintCircularBufferAddr | ULONG64 | Returns the kernel variable **KdPrintDefaultCircularBuffer**. |
| DEBUG_DATA_KdPrintCircularBufferEndAddr | ULONG64 | Returns the address of the end of the array KdPrintDefaultCircularBuffer |
| DEBUG_DATA_KdPrintWritePointerAddr | ULONG64 | Returns the address of the kernel variable **KdPrintWritePointer**. |
| DEBUG_DATA_KdPrintRolloverCountAddr | ULONG64 | Returns the address of the kernel variable **KdPrintRolloverCount**. |
| DEBUG_DATA_MmLoadedUserImageListAddr | ULONG64 | Returns the address of the kernel variable **MmLoadedUserImageList**. |
| DEBUG_DATA_PaeEnabled | BOOLEAN | Returns **TRUE** when the target system has PAE enabled.<br><br>Returns **FALSE** otherwise. |
| DEBUG_DATA_SharedUserData | ULONG64 | Returns the address in the target of the shared user-mode structure, KUSER_SHARED_DATA. The KUSER_SHARED_DATA structure is defined in ntddk.h (in the Windows Driver Kit) and ntexapi.h (in the Windows SDK).<br><br>Some of the information contained in this structure is displayed by the debugger extension **!kuser**. |
| DEBUG_DATA_ProductType | ULONG | Returns the value of the **NtProductType** field in the shared user-mode page.<br><br>This value should be interpreted the same way as the **wProductType** field of the structure OSVERSIONINFOEX, which is documented in the Windows SDK. |
| DEBUG_DATA_SuiteMask | ULONG | Returns the value of the **SuiteMask** field in the shared user-mode page.<br><br>This value should be interpreted the same way as the **wSuiteMask** field of the structure OSVERSIONINFOEX, which is documented in the Windows SDK. |
| DEBUG_DATA_DumpWriterStatus | ULONG | Returns the status of the writer of the dump file. This value is operating system and dump file type specific. |

The following values are valid for Windows XP and later versions of Windows:

| Value | Return Type | Description |
| --- | --- | --- |
| DEBUG_DATA_NtBuildLabAddr | ULONG64 | Returns the address of the kernel variable **NtBuildLab**. |
| DEBUG_DATA_KiNormalSystemCall | ULONG64 | (Itanium only) Returns the address of the kernel function **KiNormalSystemCall**. |
| DEBUG_DATA_KiProcessorBlockAddr | ULONG64 | Returns the kernel variable **KiProcessorBlock**. |
| DEBUG_DATA_MmUnloadedDriversAddr | ULONG64 | Returns the address of the kernel variable **MmUnloadedDrivers**. |
| DEBUG_DATA_MmLastUnloadedDriverAddr | ULONG64 | Returns the address of the kernel variable **MmLastUnloadedDriver**. |
| DEBUG_DATA_MmTriageActionTakenAddr | ULONG64 | Returns the address of the kernel variable **VerifierTriageActionTaken**. |
| DEBUG_DATA_MmSpecialPoolTagAddr | ULONG64 | Returns the address of the kernel variable **MmSpecialPoolTag**. |
| DEBUG_DATA_KernelVerifierAddr | ULONG64 | Returns the address of the kernel variable **KernelVerifier**. |
| DEBUG_DATA_MmVerifierDataAddr | ULONG64 | Returns the address of the kernel variable **MmVerifierData**. |
| DEBUG_DATA_MmAllocatedNonPagedPoolAddr | ULONG64 | Returns the address of the kernel variable **MmAllocatedNonPagedPool**. |
| DEBUG_DATA_MmPeakCommitmentAddr | ULONG64 | Returns the address of the kernel variable **MmPeakCommitment**. |
| DEBUG_DATA_MmTotalCommitLimitMaximumAddr | ULONG64 | Returns the address of the kernel variable **MmTotalCommitLimitMaximum**. |
| DEBUG_DATA_CmNtCSDVersionAddr | ULONG64 | Returns the address of the kernel variable **CmNtCSDVersion**. |
| DEBUG_DATA_MmPhysicalMemoryBlockAddr | ULONG64 | Returns the address of the kernel variable **MmPhysicalMemoryBlock**. |
| DEBUG_DATA_MmSessionBase | ULONG64 | Returns the address of the kernel variable **MmSessionBase**. |
| DEBUG_DATA_MmSessionSize | ULONG64 | Returns the address of the kernel variable **MmSessionSize**. |
| DEBUG_DATA_MmSystemParentTablePage | ULONG64 | (Itanium only) Returns the address of the kernel variable **MmSystemParentTablePage**. |

The following values are valid for Windows Server 2003 and later versions of Windows:

| Value | Return Type | Description |
| --- | --- | --- |
| DEBUG_DATA_MmVirtualTranslationBase | ULONG64 | Returns the address of the kernel variable **MmVirtualTranslationBase**. |
| DEBUG_DATA_OffsetKThreadNextProcessor | USHORT | Returns the offset of the **NextProcessor** field in the KTHREAD structure. |
| DEBUG_DATA_OffsetKThreadTeb | USHORT | Returns the offset of the **Teb** field in the KTHREAD structure. |
| DEBUG_DATA_OffsetKThreadKernelStack | USHORT | Returns the offset of the **KernelStack** field in the KTHREAD structure. |
| DEBUG_DATA_OffsetKThreadInitialStack | USHORT | Returns the offset of the **InitialStack** field in the KTHREAD structure. |
| DEBUG_DATA_OffsetKThreadApcProcess | USHORT | Returns the offset of the ApcState.Process field in the KTHREAD structure. |
| DEBUG_DATA_OffsetKThreadState | USHORT | Returns the offset of the **State** field in the KTHREAD structure. |
| DEBUG_DATA_OffsetKThreadBStore | USHORT | (Itanium only) Returns the offset of the **InitialBStore** field in the KTHREAD structure. |
| DEBUG_DATA_OffsetKThreadBStoreLimit | USHORT | (Itanium only) Returns the offset of the **BStoreLimit** field in the KTHREAD structure. |
| DEBUG_DATA_SizeEProcess | USHORT | Returns the size of the EPROCESS structure. |
| DEBUG_DATA_OffsetEprocessPeb | USHORT | Returns the offset of the **Peb** field in the EPROCESS structure. |
| DEBUG_DATA_OffsetEprocessParentCID | USHORT | Returns the offset of the **InheritedFromUniqueProcessId** field in the EPROCESS structure. |
| DEBUG_DATA_OffsetEprocessDirectoryTableBase | USHORT | Returns the offset of the **DirectoryTableBase** field in the EPROCESS structure. |
| DEBUG_DATA_SizePrcb | USHORT | Returns the size of the KPRCB structure. |
| DEBUG_DATA_OffsetPrcbDpcRoutine | USHORT | Returns the offset of the **DpcRoutineActive** field in the KPRCB structure. |
| DEBUG_DATA_OffsetPrcbCurrentThread | USHORT | Returns the offset of the **CurrentThread** field in the KPRCB structure. |
| DEBUG_DATA_OffsetPrcbMhz | USHORT | Returns the offset of the **MHz** field in the KPRCB structure. |
| DEBUG_DATA_OffsetPrcbCpuType | USHORT | **For Itanium processors:** Returns the offset of the **ProcessorModel** field in the KPRCB structure.<br><br>**For all other processors:** Returns the offset of the **CpuType** field in the KPRCB structure. |
| DEBUG_DATA_OffsetPrcbVendorString | USHORT | **For Itanium processors:** Returns the offset of the **ProcessorVendorString** field in the KPRCB structure.<br><br>**For all other processors:** Returns the offset of the **VendorString** field in the KPRCB structure. |
| DEBUG_DATA_OffsetPrcbProcessorState | USHORT | Returns the offset of the ProcessorState.ContextFrame field in the KPRCB structure. |
| DEBUG_DATA_OffsetPrcbNumber | USHORT | Returns the offset of the **Number** field in the KPRCB structure. |
| DEBUG_DATA_SizeEThread | USHORT | Returns the size of the ETHREAD structure. |
| DEBUG_DATA_KdPrintCircularBufferPtrAddr | ULONG64 | Returns the address of the kernel variable **KdPrintCircularBuffer**. |
| DEBUG_DATA_KdPrintBufferSizeAddr | ULONG64 | Returns the address of the kernel variable **KdPrintBufferSize**. |

### `Buffer` [out]

Receives the value of the specified debugger data. The "Return Type" column in the above table specifies the data type that is returned. The data can be accessed by casting *Buffer* to a pointer to that type.

### `BufferSize` [in]

Specifies the size in bytes of the buffer *Buffer*.

### `DataSize` [out, optional]

Receives the number of bytes used in the buffer *Buffer*. If *DataSize* is **NULL**, this information is not returned.

## Return value

| Return code | Description |
| --- | --- |
| **S_OK** | The method was successful. |

This method can also return error values. See [Return Values](https://learn.microsoft.com/windows-hardware/drivers/debugger/hresult-values) for more details.

## Remarks

Some or all of the values may be unavailable in certain debugging sessions. For example, some of the values are only available for particular versions of the operating system.

For details on the different values returned by **ReadDebuggerData**, see *Microsoft Windows Internals* by David Solomon and Mark Russinovich, the Microsoft Windows SDK, and the Windows Driver Kit (WDK).