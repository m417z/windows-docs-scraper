# ICOMAdminCatalog::GetMultipleComponentsInfo

## Description

Retrieves information about the components found in the specified files.

## Parameters

### `bstrApplIdOrName` [in]

The GUID or application name representing the application.

### `ppsaVarFileNames` [in]

An array of names of files containing the components.

### `ppsaVarCLSIDs` [out]

An array of component CLSIDs.

### `ppsaVarClassNames` [out]

An array of component class names.

### `ppsaVarFileFlags` [out]

An array for file flags containing information about the files.

#### COMAdminFileFlagLoadable
(0x00000001)

#### COMAdminFileFlagCOM (0x00000002)

#### COMAdminFileFlagContainsRS (0x00000004)

#### COMAdminFileFlagContainsComp (0x00000008)

#### COMAdminFileFlagContainsTLB (0x00000010)

#### COMAdminFileFlagSelfReg (0x00000020)

#### COMAdminFileFlagSelfUnReg (0x00000040)

#### COMAdminFileFlagUnloadableDLL (0x00000080)

#### COMAdminFileFlagDoesNotExist (0x00000100)

#### COMAdminFileFlagAlreadyInstalled (0x00000200)

#### COMAdminFileFlagBadTLB (0x00000400)

#### COMAdminFileFlagGetClassObjFailed (0x00000800)

#### COMAdminFileFlagClassNotAvailable (0x00001000)

#### COMAdminFileFlagRegistrar (0x00002000)

#### COMAdminFileFlagNoRegistrar (0x00004000)

#### COMAdminFileFlagDLLRegsvrFailed (0x00008000)

#### COMAdminFileFlagRegTLBFailed (0x00010000)

#### COMAdminFileFlagRegistrarFailed (0x00020000)

#### COMAdminFileFlagError (0x00040000)

### `ppsaVarComponentFlags` [out]

An array for the component flags used to represent information about components in files.

#### COMAdminComponentFlagTypeInfoFound (0x00000001)

#### COMAdminComponentCOMPlusPropertiesFound (0x00000002)

#### COMAdminComponentProxyFound (0x00000004)

#### COMAdminComponentInterfacesFound (0x00000008)

#### COMAdminComponentAlreadyInstalled (0x00000010)

#### COMAdminComponentNotInApplication (0x00000020)

## Return value

This method can return the standard return values E_INVALIDARG, E_OUTOFMEMORY, E_UNEXPECTED, and E_FAIL, as well as the following values.

| Return code | Description |
| --- | --- |
| **S_OK** | The method completed successfully. |
| **COMADMIN_E_OBJECTERRORS** | Errors occurred while accessing one or more objects. |

## See also

[ICOMAdminCatalog](https://learn.microsoft.com/windows/desktop/api/comadmin/nn-comadmin-icomadmincatalog)