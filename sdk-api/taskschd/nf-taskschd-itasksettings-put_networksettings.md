# ITaskSettings::put_NetworkSettings

## Description

Gets or sets the network settings object that contains a network profile identifier and name. If the [RunOnlyIfNetworkAvailable](https://learn.microsoft.com/windows/desktop/api/taskschd/nf-taskschd-itasksettings-get_runonlyifnetworkavailable) property of [ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings) is **true** and a network propfile is specified in the **NetworkSettings** property, then the task will run only if the specified network profile is available.

This property is read/write.

## Parameters

## See also

[INetworkSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-inetworksettings)

[ITaskSettings](https://learn.microsoft.com/windows/desktop/api/taskschd/nn-taskschd-itasksettings)