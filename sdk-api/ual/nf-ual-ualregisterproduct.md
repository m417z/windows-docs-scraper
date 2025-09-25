# UalRegisterProduct function

## Description

Registers a product with User Access Logging (UAL).

## Parameters

### `wszProductName` [in]

The name of the major product to register with UAL. For example, "Windows Server".

### `wszRoleName` [in]

The name of the role or minor product within the major product to be registered with UAL. For example, "DHCP".

### `wszGuid` [in]

The GUID associated with the role specified by the *wszRoleName* parameter.

## Return value

If the function succeeds, it returns **S_OK**. If it fails, it returns an error code.