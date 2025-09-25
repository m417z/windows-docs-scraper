# IFsrmFileScreenManager::get_ActionVariables

## Description

Retrieves a list of macros that you can specify in action property values.

This property is read-only.

## Parameters

## Remarks

FSRM parses the action property for the macros and substitutes the macro string with the values that are
specific to the event and computer on which the action occurred. For example, the following shows how you can
format the message text for email:
"User [Source Io Owner] has reached the quota limit for quota on [Quota Path] on server [Server]. The quota limit is [Quota Limit MB] MB and the current usage is [Quota Used MB] MB ([Quota Used Percent]% of limit)."

## See also

[FsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/fsrm/fsrmfilescreenmanager)

[IFsrmFileScreenManager](https://learn.microsoft.com/previous-versions/windows/desktop/api/fsrmscreen/nn-fsrmscreen-ifsrmfilescreenmanager)