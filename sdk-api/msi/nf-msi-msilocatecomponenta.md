# MsiLocateComponentA function

## Description

The
**MsiLocateComponent** function returns the full path to an installed component without a product code. This function attempts to determine the product using
[MsiGetProductCode](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetproductcodea), but is not guaranteed to find the correct product for the caller.
[MsiGetComponentPath](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msigetcomponentpatha) should always be called when possible.

## Parameters

### `szComponent` [in]

Specifies the component ID of the component to be located.

### `lpPathBuf` [out]

Pointer to a variable that receives the path to the component. The variable includes the terminating null character.

### `pcchBuf` [in, out]

Pointer to a variable that specifies the size, in characters, of the buffer pointed to by the *lpPathBuf* parameter. On input, this is the full size of the buffer, including a space for a terminating null character. Upon success of the
**MsiLocateComponent** function, the variable pointed to by *pcchBuf* contains the count of characters not including the terminating null character. If the size of the buffer passed in is too small, the function returns INSTALLSTATE_MOREDATA.

If *lpPathBuf* is null, *pcchBuf* can be null.

## Return value

| Value | Meaning |
| --- | --- |
| **INSTALLSTATE_NOTUSED** | The component being requested is disabled on the computer. |
| **INSTALLSTATE_ABSENT** | The component is not installed. See Remarks. |
| **INSTALLSTATE_INVALIDARG** | One of the function parameters is invalid. |
| **INSTALLSTATE_LOCAL** | The component is installed locally. |
| **INSTALLSTATE_MOREDATA** | The buffer provided was too small. |
| **INSTALLSTATE_SOURCE** | The component is installed to run from source. |
| **INSTALLSTATE_SOURCEABSENT** | The component source is inaccessible. |
| **INSTALLSTATE_UNKNOWN** | The product code or component ID is unknown. See Remarks. |

## Remarks

The
**MsiLocateComponent** function might return INSTALLSTATE_ABSENT or INSTALL_STATE_UNKNOWN, for the following reasons:

* INSTALLSTATE_ABSENT

  The application did not properly ensure that the feature was installed by calling
  [MsiUseFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiusefeaturea) and, if necessary,
  [MsiConfigureFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiconfigurefeaturea).
* INSTALLSTATE_UNKNOWN

  The feature is not published. The application should have determined this earlier by calling
  [MsiQueryFeatureState](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiqueryfeaturestatea) or
  [MsiEnumFeatures](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msienumfeaturesa). The application makes these calls while it initializes. An application should only use features that are known to be published. Since INSTALLSTATE_UNKNOWN should have been returned by
  [MsiUseFeature](https://learn.microsoft.com/windows/desktop/api/msi/nf-msi-msiusefeaturea) as well, either
  **MsiUseFeature** was not called, or its return value was not properly checked.

> [!NOTE]
> The msi.h header defines MsiLocateComponent as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[Component-Specific Functions](https://learn.microsoft.com/windows/desktop/Msi/installer-function-reference)