# _D3DKMT_CREATEKEYEDMUTEX2_FLAGS structure

## Description

Indicates how a handle to a keyed mutex is specified.

## Members

### `NtSecuritySharing`

A UINT value that specifies whether the keyed mutex is shared or has a global **D3DKMT_HANDLE** kernel-mode handle to the resource.

If **NtSecuritySharing** is set to 1 (**TRUE**), the keyed mutex is shared using the [D3DKMTShareObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects) function but does not have a global **D3DKMT_HANDLE** handle to the resource. In this case, the process handle to the resource is provided by the [D3DKMT_CREATEKEYEDMUTEX2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2).**hKeyedMutex** member in a call to the [D3DKMTCreateKeyedMutex2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex2) function.

If **NtSecuritySharing** is set to zero (**FALSE**), the keyed mutex has a global **D3DKMT_HANDLE** handle to the resource provided by the [D3DKMT_CREATEKEYEDMUTEX2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2).**hSharedHandle** member in a call to [D3DKMTCreateKeyedMutex2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex2).

### `Reserved`

This member is reserved and should be set to zero. Setting this member is equivalent to setting the remaining 31 bits (0xFFFFFFFE) of a 32-bit value to zeros.

### `Value` [in]

A member in the union that **D3DKMT_CREATEKEYEDMUTEX2_FLAGS** contains that can hold a 32-bit value that identifies the keyed mutex sharing type.

## See also

[D3DKMTCreateKeyedMutex2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtcreatekeyedmutex2)

[D3DKMTShareObjects](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/nf-d3dkmthk-d3dkmtshareobjects)

[D3DKMT_CREATEKEYEDMUTEX2](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3dkmthk/ns-d3dkmthk-_d3dkmt_createkeyedmutex2)