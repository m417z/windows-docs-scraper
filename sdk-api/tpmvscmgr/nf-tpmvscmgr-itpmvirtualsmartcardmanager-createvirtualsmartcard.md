# ITpmVirtualSmartCardManager::CreateVirtualSmartCard

## Description

Creates a TPM virtual smart card with the given parameters.

## Parameters

### `pszFriendlyName` [in]

Display name of the smart card reader node. This is shown in the Device Manager, but it is not the reader name as seen by the smart card resource manager (SCRM).

### `bAdminAlgId` [in]

Algorithm identifier of the admin key. Currently, to work with the inbox GIDS minidriver, this value should be VSC_DEFAULT_ADMIN_ALGORITHM_ID (3-key triple DES with ISO/IEC 9797 padding method 2 in CBC chaining mode).

### `pbAdminKey` [in]

Pointer to a byte array that contains the admin key of the virtual smart card to be created.

### `cbAdminKey` [in]

Size, in bytes, of the byte array pointed to by the *pbAdminKey* parameter.

### `pbAdminKcv` [in, optional]

Pointer to a byte array that contains the key check value of the admin key. Key check value is defined as the first 3 bytes of the output BLOB when using the admin key to encrypt a block of zeros. If the key check value is not provided, there will be no integrity check for the admin key.

### `cbAdminKcv` [in]

Size, in bytes, of the byte array pointed to by the *pbAdminKcv* parameter.

### `pbPuk` [in, optional]

Pointer to a byte array that contains the PIN unlock key (PUK) value of the virtual smart card. It is usually a sequence of ASCII characters with a minimal length of 8 characters. If the PUK is not provided, the virtual smart card will be created without a PUK role and instead will use the challenge/response-based PIN reset through the admin role.

### `cbPuk` [in]

Size, in bytes, of the byte array pointed to by the *pbPuk* parameter.

### `pbPin` [in]

Pointer to a byte array that contains the PIN value of the virtual smart card. It is usually a sequence of ASCII characters with a length of 8 characters minimum and 127 characters maximum.

### `cbPin` [in]

Size, in bytes, of the byte array pointed to by the *pbPin* parameter.

### `fGenerate` [in]

Indicates whether the virtual smart card needs to be provisioned with all necessary files required by the base CSP and smart card KSP.

### `pStatusCallback` [in, optional]

Pointer to a [ITpmVirtualSmartCardManagerStatusCallback](https://learn.microsoft.com/windows/desktop/api/tpmvscmgr/nn-tpmvscmgr-itpmvirtualsmartcardmanagerstatuscallback) interface. The TPM virtual smart card manager uses this callback interface to communicate the progress or error during virtual smart card creation. If the *pStatusCallback* parameter is **NULL**, no progress is reported to the client before the operation completes.

### `ppszInstanceId` [out]

Pointer to a pointer to a Unicode buffer to receive the instance ID of the created virtual smart card.

### `pfNeedReboot` [out]

Pointer to a Boolean value to receive whether the requested operation needs to reboot the computer.

## Return value

If the method succeeds, it returns **S_OK**.

If the method fails, it returns a Win32 error code.

## Remarks

When the method succeeds, the *ppszInstanceId* parameter points to the Unicode buffer that contains the instance identifier of the newly created TPM virtual smart card reader. When you have finished using the buffer, the caller needs to free the buffer on the client by calling the [CoTaskMemFree](https://learn.microsoft.com/windows/desktop/api/combaseapi/nf-combaseapi-cotaskmemfree) function, as directed in the COM memory management rules.

## See also

[ITpmVirtualSmartCardManager](https://learn.microsoft.com/windows/desktop/api/tpmvscmgr/nn-tpmvscmgr-itpmvirtualsmartcardmanager)