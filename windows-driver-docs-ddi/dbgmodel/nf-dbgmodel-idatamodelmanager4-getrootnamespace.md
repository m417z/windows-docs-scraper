## Description

The GetRootNamespace method returns the data model's root namespace. This is an object which the data model manages and into which the debug host places certain objects. It is expected that at least the following hierarchy is exposed by every host:

```cpp
• Debugger - represents the debugger which is hosting the data model

    o Sessions - a collection of sessions which represent each debug target

         Processes -- a collection of processes which represent each process in the debug target

            - Threads -- a collection of threads which represent each thread within a given process in the debug target
```

## Parameters

### `rootNamespace`

The root namespace of the data model is returned here.

## Return value

This method returns HRESULT that indicates success or failure.

## Remarks

**Sample Code**

```cpp
ComPtr<IDataModelManager4> spManager; /* get the data model manager */

ComPtr<IModelObject> spRootNamespace;
if (SUCCEEDED(spManager->GetRootNamespace(&spRootNamespace)))
{
    // We've gotten the root namespace successfully.  Find the Debugger property.
    ComPtr<IModelObject> spDebugger;
    if (SUCCEEDED(spRootNamespace->GetKeyValue(L"Debugger", &spDebugger, nullptr)))
    {
        // We've gotten the "Debugger" property successfully.  Find the
        // Sessions property.
        ComPtr<IModelObject> spSessions;
        if (SUCCEEDED(spDebugger->GetKeyValue(L"Sessions", &spSessions, nullptr)))
        {
            // We've gotten the "Sessions" property successfully.
        }
    }
}

```

## See also

[IDataModelManager4 interface](https://learn.microsoft.com/windows-hardware/drivers/ddi/dbgmodel/nn-dbgmodel-idatamodelmanager4)