
#include <rtems.h>
#include <sys/types.h>
#include <rtems/rtems/status.h>
#include <libcpu/memoryprotection.h>
/*#include <libcpu/pagetable.h>
 #include "pagetable_.h"*/


/*this is a mid level API used to operate page table 
 *mainly used by memory protect manager
 */
rtems_status_code rtems_memory_management_verify_permissions( uint32_t attr)
{
  return  _CPU_Memory_protection_Verify_permission(attr);
}

void rtems_pagetable_initialize( void )
{
  _CPU_Pagetable_Initialize();
}

rtems_status_code rtems_memory_management_verify_size(
    size_t size
) {
  rtems_status_code status;
  ISR_Level         level;
  _ISR_Disable( level );
    status = _CPU_Memory_management_Verify_size(size);
  _ISR_Enable( level );
  return status;
}

rtems_status_code rtems_pagetable_update_permissions(
  uint32_t ea, 
  int cache_attr, 
  int mprot)
{
  return _CPU_Pte_Change_Attributes( ea, cache_attr, mprot);
}


