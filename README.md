<div align="center">
<h1>Digital Clock</h1>
</div>

A digital clock in c

<div id="clock"></div>
<script>
  function updateClock() {
    const now = new Date();
    document.getElementById("clock").textContent = now.toLocaleTimeString();
  }
  setInterval(updateClock, 1000);
  updateClock();
</script>
