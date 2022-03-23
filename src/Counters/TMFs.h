#pragma once

template <bool condition, class Then, class Else>
struct IF {
  typedef Then RET;
};

template <class Then, class Else>
struct IF<false, Then, Else> {
  typedef Else RET;
};
