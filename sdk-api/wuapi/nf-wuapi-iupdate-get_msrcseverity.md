# IUpdate::get_MsrcSeverity

## Description

Gets the Microsoft Security Response Center severity rating of the update.

This property is read-only.

## Parameters

## Remarks

The following ratings are the possible severity ratings of a security issue that is fixed by an update. These ratings were revised by the Microsoft Security Response Center in November 2002.

| Term | Description |
| --- | --- |
| Critical | A security issue whose exploitation could allow the propagation of an Internet worm without user action. |
| Important | A security issue whose exploitation could result in compromise of the confidentiality, integrity, or availability of users' data, or of the integrity or availability of processing resources. |
| Moderate | Exploitation is mitigated to a significant degree by factors such as default configuration, auditing, or difficulty of exploitation. |
| Low | A security issue whose exploitation is extremely difficult, or whose impact is minimal. |

## See also

[IUpdate](https://learn.microsoft.com/windows/desktop/api/wuapi/nn-wuapi-iupdate)