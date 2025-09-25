typedef struct {
  void  *Context;
  void  )(void *Context,DWORD Size)  *(*AllocRoutine;
  void((void *Context, void *Address) * )FreeRoutine;
} PSS_ALLOCATOR;