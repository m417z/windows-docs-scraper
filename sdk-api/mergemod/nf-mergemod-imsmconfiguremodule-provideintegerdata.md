# IMsmConfigureModule::ProvideIntegerData

## Description

The
**ProvideIntegerData** method retrieves integer data from the client tool. For more information, see the
[ProvideIntegerData](https://learn.microsoft.com/windows/desktop/Msi/configuremodule-provideintegerdata) method of the
[ConfigureModule](https://learn.microsoft.com/windows/desktop/Msi/configuremodule-object) object.

## Parameters

### `Name` [in]

If the tool does not need to provide any configuration data for this Name value, the function should return S_FALSE. In this case Mergemod.dll ignores the value of the *ConfigData* argument and will use the Default value from the ModuleConfiguration table.

### `ConfigData` [out]

The tool should return S_OK and provide the appropriate customization text in *ConfigData*. The client tool is responsible for allocating the data, but Mergemod.dll is responsible for releasing the memory.

## Return value

Any return code other than S_OK or S_FALSE causes an error to be logged (if a log is open) and results in the merge failing.

| Value | Meaning |
| --- | --- |
| **S_FALSE** | The tool does not need to provide configuration data. |
| **S_OK** | Function succeeded. |

## Remarks

The client may be called no more than once for each record in the
[ModuleConfiguration table](https://learn.microsoft.com/windows/desktop/Msi/moduleconfiguration-table). Note that Mergemod.dll never makes multiple calls to the client for the same "Name" value. If no record in the ModuleSubstitution table uses the property, an entry in the ModuleConfiguration table causes no calls to the client.

## See also

[IMsmConfigureModule](https://learn.microsoft.com/windows/desktop/api/mergemod/nn-mergemod-imsmconfiguremodule)

[Merge Module Automation](https://learn.microsoft.com/windows/desktop/Msi/merge-module-automation)