# CM_Enumerate_Enumerators_ExW function

## Description

[Beginning with Windows 8 and Windows Server 2012, this function has been deprecated. Please use [CM_Enumerate_Enumerators](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_enumerate_enumeratorsw) instead.]

The **CM_Enumerate_Enumerators_Ex** function enumerates a local or a remote machine's device enumerators, by supplying each enumerator's name.

## Parameters

### `ulEnumIndex` [in]

Caller-supplied index into the machine's list of device enumerators. For more information, see the following **Remarks** section.

### `Buffer` [out]

Address of a buffer to receive an enumerator name. This buffer should be MAX_DEVICE_ID_LEN-sized (or, set *Buffer* to zero and obtain the actual name length in the location referenced by **puLength**).

### `pulLength` [in, out]

Caller-supplied address of a location to hold the buffer size. The caller supplies the length of the buffer pointed to by *Buffer*. The function replaces this value with the actual size of the enumerator's name string. If the caller-supplied buffer length is too small, the function supplies the required buffer size and returns CR_BUFFER_SMALL.

### `ulFlags` [in]

Not used, must be zero.

### `hMachine` [in, optional]

Caller-supplied machine handle, obtained from a previous call to [CM_Connect_Machine](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_connect_machinew).

**Note** Using this function to access remote machines is not supported beginning with Windows 8 and Windows Server 2012, as this functionality has been removed.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

To enumerate the local or a remote machine's device enumerators, call **CM_Enumerate_Enumerators_Ex** repeatedly, starting with a *ulEnumIndex* index value of zero, and incrementing the index value with each subsequent call until the function returns CR_NO_SUCH_VALUE.

After enumerator names have been obtained, the names can be used as input to [CM_Get_Device_ID_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_lista).

 Functionality to access remote machines has been removed in Windows 8 and Windows Server 2012 and later operating systems thus you cannot access remote machines when running on these versions of Windows.

## See also

[CM_Enumerate_Enumerators](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_enumerate_enumeratorsw)