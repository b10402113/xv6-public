#include "types.h"
#include "user.h"
#include "date.h"

int
main(int argc, char *argv[])
{
  struct rtcdate r;

  if (date(&r)) {
    printf(2, "time failed\n");
    exit();
  }

  printf(1,">>> today is %d/%d/%d\n", r.year, r.month, r.day);
  printf(1,">>> time is  %d:%d:%d\n", r.hour, r.minute, r.second);
  exit();
}
