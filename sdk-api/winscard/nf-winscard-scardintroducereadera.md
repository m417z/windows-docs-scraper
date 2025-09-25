# SCardIntroduceReaderA function

## Description

The **SCardIntroduceReader** function introduces a new name for an existing [smart card](https://learn.microsoft.com/windows/desktop/SecGloss/s-gly) [reader](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly).

**Note** Smart card readers are automatically introduced to the system; a smart card reader vendor's setup program can also introduce a smart card reader to the system.

## Parameters

### `hContext` [in]

Handle that identifies the [resource manager context](https://learn.microsoft.com/windows/desktop/SecGloss/r-gly). The resource manager context is set by a previous call to
[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext). This parameter cannot be **NULL**.

### `szReaderName` [in]

Display name to be assigned to the reader.

### `szDeviceName` [in]

System name of the smart card reader, for example, "MyReader 01".

## Return value

This function returns different values depending on whether it succeeds or fails.

| Return code | Description |
| --- | --- |
| **Success** | SCARD_S_SUCCESS. |
| **Failure** | An error code. For more information, see [Smart Card Return Values](https://learn.microsoft.com/windows/desktop/SecAuthN/authentication-return-values). |

## Remarks

All readers installed on the system are automatically introduced by their system name. Typically, **SCardIntroduceReader** is called only to change the name of an existing reader.

The **SCardIntroduceReader** function is a database management function. For more information on other database management functions, see
[Smart Card Database Management Functions](https://learn.microsoft.com/windows/desktop/SecAuthN/smart-card-database-management-functions).

To remove a reader, use
[SCardForgetReader](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetreadera).

#### Examples

The following example shows introducing a smart card reader.

```cpp
// This example renames the reader name.
// This is a two-step process (first add the new
// name, then forget the old name).
LPBYTE    pbAttr = NULL;
DWORD     cByte = SCARD_AUTOALLOCATE;
LONG      lReturn;

// Step 1: Add the new reader name.
// The device name attribute is a necessary value.
// hCardHandle was set by a previous call to SCardConnect.
lReturn = SCardGetAttrib(hCardHandle,
                         SCARD_ATTR_DEVICE_SYSTEM_NAME,
                         (LPBYTE)&pbAttr,
                         &cByte);
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardGetAttrib\n");
    exit(1);  // Or other error action
}
// Add the reader name.
// hContext was set earlier by SCardEstablishContext.
lReturn = SCardIntroduceReader(hContext,
                               TEXT("My New Reader Name"),
                               (LPCTSTR)pbAttr );
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardIntroduceReader\n");
    exit(1);  // Or other error action
}

// Step 2: Forget the old reader name.
lReturn = SCardForgetReader(hContext,
                            (LPCTSTR)pbAttr );
if ( SCARD_S_SUCCESS != lReturn )
{
    printf("Failed SCardForgetReader\n");
    exit(1);  // Or other error action
}

// Free the memory when done.
lReturn = SCardFreeMemory( hContext, pbAttr );

```

> [!NOTE]
> The winscard.h header defines SCardIntroduceReader as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[SCardEstablishContext](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardestablishcontext)

[SCardForgetReader](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardforgetreadera)

[SCardIntroduceCardType](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducecardtypea)

[SCardIntroduceReaderGroup](https://learn.microsoft.com/windows/desktop/api/winscard/nf-winscard-scardintroducereadergroupa)