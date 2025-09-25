typedef struct _RILADDRESS {
  DWORD                     cbSize;
  DWORD                     dwParams;
  RILADDRESSTYPE            dwType;
  RILADDRESSNUMPLAN         dwNumPlan;
  WCHAR [MAXLENGTH_ADDRESS] wszAddress;
} RILADDRESS, RILADDRESS;