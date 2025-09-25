# IApplicationActivationManager::ActivateApplication

## Description

Activates the specified Windows Store app for the generic launch contract (Windows.Launch) in the current session.

## Parameters

### `appUserModelId` [in]

The application user model ID of the Windows Store app.

### `arguments` [in]

A pointer to an optional, app-specific, argument string.

### `options` [in]

One or more of the following flags used to support design mode, debugging, and testing scenarios.

#### AO_NONE (0x00000000)

No flags are set.

#### AO_DESIGNMODE (0x00000001)

The app is being activated for design mode, so it can't create its normal window. The creation of the app's window must be done by design tools that load the necessary components by communicating with a designer-specified service on the site chain established through the activation manager. Note that this means that the splash screen seen during regular activations won't be seen.

Note that you must [enable debug mode](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-enabledebugging) on the app's package to successfully use design mode.

#### AO_NOERRORUI (0x00000002)

Do not display an error dialog if the app fails to activate.

#### AO_NOSPLASHSCREEN (0x00000004)

Do not display the app's splash screen when the app is activated. You must [enable debug mode](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-enabledebugging) on the app's package when you use this flag; otherwise, the PLM will terminate the app after a few seconds.

#### AO_PRELAUNCH (0x2000000)

The application is being activated in prelaunch mode. This value is supported starting in Windows 10.

### `processId` [out]

A pointer to a value that, when this method returns successfully, receives the process ID of the app instance that fulfills this contract.

## Return value

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IApplicationActivationManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iapplicationactivationmanager)

[IPackageDebugSettings::EnableDebugging](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ipackagedebugsettings-enabledebugging)