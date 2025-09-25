# ITPluggableTerminalSuperclassRegistration::Add

## Description

The
**Add** method adds a pluggable terminal superclass to the registry. If the superclass already exists, the method modifies the information for the superclass.

## Return value

This method can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | Method succeeded. |
| **E_FAIL** | Method failed. |

## Remarks

The
**Add** method adds a new terminal superclass if the CLSID does not exist as an entry in the registry. The method modifies the information about a terminal superclass if the CLSID already exists in the registry.

If the CLSID for the terminal superclass was not set for terminal superclass, the
**Add** method fails.

## See also

[Delete](https://learn.microsoft.com/windows/desktop/api/termmgr/nf-termmgr-itpluggableterminalsuperclassregistration-delete)

[ITPluggableTerminalSuperclassRegistration](https://learn.microsoft.com/windows/desktop/api/termmgr/nn-termmgr-itpluggableterminalsuperclassregistration)