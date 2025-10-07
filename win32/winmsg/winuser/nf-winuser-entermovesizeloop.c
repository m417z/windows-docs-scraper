enum MOVESIZE_OPERATION
{
    MSO_SIZE_LEFT =             1,
    MSO_SIZE_RIGHT =            2,
    MSO_SIZE_TOP =              3,
    MSO_SIZE_TOPLEFT =          4,
    MSO_SIZE_TOPRIGHT =         5,
    MSO_SIZE_BOTTOM =           6,
    MSO_SIZE_BOTTOMLEFT =       7,
    MSO_SIZE_BOTTOMRIGHT =      8,
    MSO_MOVE =                  9,
};

BOOL EnterMoveSizeLoop(
    HWND hwnd,
    POINT ptCursor,
    MOVESIZE_OPERATION moveSizeCode);