# WDF_COINSTALLER_INSTALL_OPTIONS_INIT function

## Description

[Applies to KMDF only]

The **WDF_COINSTALLER_INSTALL_OPTIONS_INIT** function initializes a [WDF_COINSTALLER_INSTALL_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/ns-wdfinstaller-_wdf_coinstaller_install_options) structure.

## Parameters

### `ClientOptions` [out]

A pointer to a [WDF_COINSTALLER_INSTALL_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/ns-wdfinstaller-_wdf_coinstaller_install_options) structure.

## Remarks

The **WDF_COINSTALLER_INSTALL_OPTIONS_INIT** function zeros the specified [WDF_COINSTALLER_INSTALL_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/ns-wdfinstaller-_wdf_coinstaller_install_options) structure and sets the structure's **Size** member.

#### Examples

The following code example initializes a [WDF_COINSTALLER_INSTALL_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/ns-wdfinstaller-_wdf_coinstaller_install_options) structure.

```cpp
WDF_COINSTALLER_INSTALL_OPTIONS clientOptions;
WDF_COINSTALLER_INSTALL_OPTIONS_INIT(&clientOptions);
```

## See also

[WDF_COINSTALLER_INSTALL_OPTIONS](https://learn.microsoft.com/windows-hardware/drivers/ddi/wdfinstaller/ns-wdfinstaller-_wdf_coinstaller_install_options)