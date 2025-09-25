# RM_WRITE_STATUS_CALLBACK callback function

## Description

The **RM_WRITE_STATUS_CALLBACK** function can be implemented by the user interface that controls the Restart Manager. The installer that started the Restart Manager session can pass a pointer to this function to the Restart Manager functions to receive a percentage of completeness. The percentage of completeness is strictly increasing and describes the current operation being performed and the name of the application being affected.

## Parameters

### `nPercentComplete` [in]

An integer value between 0 and 100 that indicates the percentage of the total number of applications that have either been shut down or restarted.

## See also

[RmRestart](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmrestart)

[RmShutdown](https://learn.microsoft.com/windows/desktop/api/restartmanager/nf-restartmanager-rmshutdown)