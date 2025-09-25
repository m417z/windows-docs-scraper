## Description

The **PktMonClntSetComponentProperty** function sets a property for a specific component.

## Parameters

### `CompContext`

Pointer to the **[PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)** structure that holds the context for the component.

### `CompProperty`

Pointer to the **[PKTMON_COMPONENT_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_property)** structure that describes the property to be set.

## Return value

If the function succeeds, it returns `STATUS_SUCCESS`. Otherwise, it returns a `NTSTATUS` error code.

## Remarks

Use the **PktMonClntSetComponentProperty** function to set various properties for a component. Call this function once for each property. These properties provide detailed information about the component, such as its interface ID, name, etc. You can display the properties of the components using the `pktmon` command:

```cmd
Pktmon.exe list -a
```

The properties are defined in the **PKTMON_COMPONENT_PROPERTY** structure and can include interface indices, GUIDs, MAC addresses, and other relevant information. Each property is identified by an **Id** from the **PKTMON_COMPONENT_PROPERTY_ID** enumeration.

## See also

- **[PKTMON_COMPONENT_CONTEXT](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_context)**
- **[PKTMON_COMPONENT_PROPERTY](https://learn.microsoft.com/windows-hardware/drivers/ddi/pktmonclntk/ns-pktmonclntk-pktmon_component_property)**

### Example

```cpp
NTSTATUS PktMonApiTstSetComponentProperties()
{
    NTSTATUS status = STATUS_SUCCESS;
    PKTMON_COMPONENT_PROPERTY compProp = {0};

    compProp.Id = PktMonCompProp_IfIndex;
    compProp.IfIndex = 100;
    status = PktMonClntSetComponentProperty(&PktMonComp, &compProp);
    if (STATUS_SUCCESS != status)
    {
        // Log error
        return status;
    }

    return status;
}
```