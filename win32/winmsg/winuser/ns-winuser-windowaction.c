enum WINDOW_ACTION_KINDS
{
    WAK_NONE                    = 0x0000,

    WAK_VISIBILITY              = 0x0001,
    WAK_POSITION                = 0x0002,
    WAK_SIZE                    = 0x0004,
    WAK_INSERT_AFTER            = 0x0008,
    WAK_ACTIVATE                = 0x0010,
    WAK_PLACEMENT_STATE         = 0x0020,
    WAK_NORMAL_RECT             = 0x0040,
    WAK_MOVE_TO_MONITOR         = 0x0080,
    WAK_FIT_TO_MONITOR          = 0x0100,
    WAK_DISPLAY_CHANGE          = 0x0200,
    WAK_SYSTEM_OPERATION        = 0x0400,
};

enum WINDOW_ACTION_MODIFIERS
{
    WAM_NONE                    = 0x0000,

    WAM_FRAME_BOUNDS            = 0x0001,
    WAM_ACTIVATE_FOREGROUND     = 0x0002,
    WAM_ACTIVATE_INPUT          = 0x0004,
    WAM_ACTIVATE_NO_ZORDER      = 0x0008,
    WAM_INSERT_AFTER_NO_OWNER   = 0x0010,
    WAM_RESTORE_TO_NORMAL       = 0x0020,
    WAM_RESTORE_TO_MAXIMIZED    = 0x0040,
    WAM_RESTORE_TO_ARRANGED     = 0x0080,
    WAM_WORK_AREA               = 0x0100,
    WAM_DPI                     = 0x0200,
    WAM_SCALED_TO_MONITOR       = 0x0400,
};

enum WINDOW_PLACEMENT_STATE
{
    WPS_NORMAL                  = 0,
    WPS_MAXIMIZED               = 1,
    WPS_MINIMIZED               = 2,
    WPS_ARRANGED                = 3,
};

struct WINDOW_ACTION
{
    WINDOW_ACTION_KINDS         kinds;
    WINDOW_ACTION_MODIFIERS     modifiers;

    BOOL                        visible;
    POINT                       position;
    SIZE                        size;
    HWND                        insertAfter;
    WINDOW_PLACEMENT_STATE      placementState;
    RECT                        normalRect;
    RECT                        workArea;
    UINT                        dpi;
    POINT                       pointOnMonitor;
    UINT                        monitorTopologyId;
};