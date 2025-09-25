# RoRegisterActivationFactories function

## Description

Registers an array out-of-process activation factories for a Windows Runtime exe server.

## Parameters

### `activatableClassIds` [in]

Type: **[HSTRING](https://learn.microsoft.com/windows/desktop/WinRT/hstring)***

An array of class identifiers that are associated with activatable runtime classes.

### `activationFactoryCallbacks` [in]

Type: **[PFNGETACTIVATIONFACTORY](https://learn.microsoft.com/previous-versions/br205771(v=vs.85))***

An array of callback functions that you can use to retrieve the activation factories that correspond with *activatableClassIds*.

### `count` [in]

Type: **UINT32**

The number of items in the *activatableClassIds* and *activationFactoryCallbacks* arrays.

### `cookie` [out]

Type: **[RO_REGISTRATION_COOKIE](https://learn.microsoft.com/windows/desktop/WinRT/ro-registration-cookie)***

A cookie that identifies the registered factories.

## Return value

Type: **HRESULT**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The activation factory was registered successfully. |
| **E_POINTER** | *cookie* is **NULL**. |
| **CO_E_NOT_SUPPORTED** | The thread is in a neutral apartment. |
| **CO_E_NOTINITIALIZED** | The thread has not been initialized in the Windows Runtime by calling the [RoInitialize](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roinitialize) function. |
| **CO_E_ALREADYINITIALIZED** | The factory has been initialized already. |
| **REGDB_E_CLASSNOTREG** | The class is not registered as OutOfProc. |

## Remarks

The **RoRegisterActivationFactories** function enables an exe server to register multiple activation factories without experiencing a race condition.

## See also

[RO_REGISTRATION_COOKIE](https://learn.microsoft.com/windows/desktop/WinRT/ro-registration-cookie)

[RoInitialize](https://learn.microsoft.com/windows/desktop/api/roapi/nf-roapi-roinitialize)