# CM_Enumerate_EnumeratorsW function

## Description

The **CM_Enumerate_Enumerators** function enumerates the local machine's device enumerators by supplying each enumerator's name.

## Parameters

### `ulEnumIndex` [in]

Caller-supplied index into the machine's list of device enumerators. For more information, see the following **Remarks** section.

### `Buffer` [out]

Address of a buffer to receive an enumerator name. This buffer should be MAX_DEVICE_ID_LEN-sized (or, set *Buffer* to zero and obtain the actual name length in the location referenced by *puLength*).

### `pulLength` [in, out]

Caller-supplied address of a location to hold the buffer size. The caller supplies the length of the buffer pointed to by *Buffer*. The function replaces this value with the actual size of the enumerator's name string. If the caller-supplied buffer length is too small, the function supplies the required buffer size and returns CR_BUFFER_SMALL.

### `ulFlags` [in]

Not used, must be zero.

## Return value

If the operation succeeds, the function returns CR_SUCCESS. Otherwise, it returns one of the CR_-prefixed error codes defined in *Cfgmgr32.h*.

## Remarks

To enumerate the local machine's device enumerators, call **CM_Enumerate_Enumerators** repeatedly, starting with a *ulEnumIndex* index value of zero. and incrementing the index value with each subsequent call until the function returns CR_NO_SUCH_VALUE.

After enumerator names have been obtained, the names can be used as input to [CM_Get_Device_ID_List](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_get_device_id_lista).

## See also

[CM_Enumerate_Enumerators_Ex](https://learn.microsoft.com/windows/desktop/api/cfgmgr32/nf-cfgmgr32-cm_enumerate_enumerators_exw)