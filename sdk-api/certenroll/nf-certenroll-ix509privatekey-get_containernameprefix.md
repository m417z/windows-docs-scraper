# IX509PrivateKey::get_ContainerNamePrefix

## Description

The **ContainerNamePrefix** property specifies or retrieves a prefix added to the name of the key container.

This property is read/write.

## Parameters

## Remarks

A prefix can contain any string limited to the maximum length of the key container name and to legal container name characters. For example, if you do not call the [ContainerName](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-get_containername) property to specify a key container name, one is automatically created when the [Create](https://learn.microsoft.com/windows/desktop/api/certenroll/nf-certenroll-ix509privatekey-create) method is called, and the prefix to the container name will be the string "lp". For another example, if you are creating a test harness and want to differentiate key containers by the programs that generated them, you can use the name of the executable as the prefix.

## See also

[IX509PrivateKey](https://learn.microsoft.com/windows/desktop/api/certenroll/nn-certenroll-ix509privatekey)