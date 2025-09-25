# SetIScsiGroupPresharedKey function

## Description

The **SetIscsiGroupPresharedKey** function establishes the default group preshared key for all initiators on the computer.

## Parameters

### `KeyLength` [in]

The size, in bytes, of the preshared key.

### `Key` [in]

The buffer that contains the preshared key.

### `Persist`

If **true**, this parameter indicates that the preshared key information will be stored in non-volatile memory and will persist across restarts of the computer or the iSCSI initiator service.

## Return value

Returns ERROR_SUCCESS if the operation succeeds. Otherwise, it returns the appropriate Win32 or iSCSI error code.