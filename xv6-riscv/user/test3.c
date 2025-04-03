#include "kernel/types.h"
#include "kernel/stat.h"
#include "user.h"

int
main(int _ac, char *_av[])
{
  int rv, rv0;
  struct iostats st;
  struct iostats st0;

  fprintf(2, "Hello\n");
  rv = getiostats(2, &st);
  fprintf(1, "hello1 stats(2) (r: %d, w: %d) -> %d\n", st.read_bytes, st.write_bytes, rv);

  rv0 = getiostats(2, &st0);

  fprintf(2, "Hello\n");
  rv = getiostats(2, &st);

  fprintf(1, "base stats0(2) (r: %d, w: %d) -> %d\n", st0.read_bytes, st0.write_bytes, rv0);
  fprintf(1, "raw stats(2) (r: %d, w: %d) -> %d\n", st.read_bytes, st.write_bytes, rv);
  fprintf(1, "diff stats(2) (r: %d, w: %d) -> %d\n",
         st.read_bytes - st0.read_bytes,
         st.write_bytes - st0.write_bytes,
         rv0 + rv);

  fprintf(1, "test3 done\n");
  exit(0);
  return 0;
}
