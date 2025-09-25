typedef enum FAX_JOB_STATUS_ENUM {
  fjsPENDING = 0x1,
  fjsINPROGRESS = 0x2,
  fjsFAILED = 0x8,
  fjsPAUSED = 0x10,
  fjsNOLINE = 0x20,
  fjsRETRYING = 0x40,
  fjsRETRIES_EXCEEDED = 0x80,
  fjsCOMPLETED = 0x100,
  fjsCANCELED = 0x200,
  fjsCANCELING = 0x400,
  fjsROUTING = 0x800
} ;